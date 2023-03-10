#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#include <gl.h>
#include "rasterizer.h"
#include "connection.h"

static const int32_t DISPLAY_WIDTH = XMAXSCREEN + 1;
static const int32_t DISPLAY_HEIGHT = YMAXSCREEN + 1;
static int snap_vertices = 0;

static float the_linewidth;
static uint16_t the_pattern[16];
static int pattern_enabled = 0;
static int zbuffer_enabled;

typedef uint16_t z_t;

static unsigned char pixel_colors[480][800][4];
static unsigned char *hwfb = NULL;
static z_t pixel_depths[480][800];
static const int Z_SHIFT = 16;

static float min(float a, float b)
{
    return (a < b) ? a : b;
}

static float clamp(float v, float low, float high)
{
    return v > high ? high : (v < low ? low : v);
}

float triArea2f(float v0[2], float v1[2], float v2[2])
{
    float      s, a, b, c;
    float      av[2], bv[2], cv[2];

    /*
     * faster area calculation?  length of cross product / 2? */
    av[0] = v1[0] - v0[0];
    av[1] = v1[1] - v0[1];

    bv[0] = v2[0] - v1[0];
    bv[1] = v2[1] - v1[1];

    cv[0] = v0[0] - v2[0];
    cv[1] = v0[1] - v2[1];

    a = sqrt(av[0] * av[0] + av[1] * av[1]);
    b = sqrt(bv[0] * bv[0] + bv[1] * bv[1]);
    c = sqrt(cv[0] * cv[0] + cv[1] * cv[1]);

    s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void calcBaryCoords2f(float v0[2], float v1[2], float v2[2], float p[2],
    float *a, float *b, float *c)
{
    float area;
    area = triArea2f(v0, v1, v2);
    *a = triArea2f(v1, v2, p) / area;
    *b = triArea2f(v2, v0, p) / area;
    *c = triArea2f(v0, v1, p) / area;
}

typedef void (*pixelFunc)(int x, int y, float bary[3], void *data);

void boxi2DClear(int bbox[4])
{
    bbox[0] = INT_MAX;
    bbox[1] = INT_MIN;
    bbox[2] = INT_MAX;
    bbox[3] = INT_MIN;
}

void boxi2DGrow(int bbox[4], float *v)
{
    if(floor(v[0]) < bbox[0]) bbox[0] = floor(v[0]);
    if(ceil(v[0]) > bbox[1]) bbox[1] = ceil(v[0]);
    if(floor(v[1]) < bbox[2]) bbox[2] = floor(v[1]);
    if(ceil(v[1]) > bbox[3]) bbox[3] = ceil(v[1]);
}

void boxi2DIsect(int bb1[4], int bb2[4], int r[4])
{
    r[0] = (bb1[0] < bb2[0]) ? bb1[0] : bb1[0];
    r[1] = (bb1[1] > bb2[1]) ? bb1[1] : bb1[1];
    r[2] = (bb1[2] < bb2[2]) ? bb1[2] : bb1[2];
    r[3] = (bb1[3] > bb2[3]) ? bb1[3] : bb1[3];
}

float evalHalfPlane(float v0[2], float v1[2], float v2[2], float x, float y)
{
    float n[2];

    n[0] = - (v1[1] - v0[1]);
    n[1] = v1[0] - v0[0];

    return ((x - v0[0]) * n[0] + (y - v0[1]) * n[1]) / 
        ((v2[0] - v0[0]) * n[0] + (v2[1] - v0[1]) * n[1]);
}

void calcHalfPlaneDiffs(float v0[2], float v1[2], float v2[2],
    float *dx, float *dy)
{
    *dx = evalHalfPlane(v0, v1, v2, 1, 0) - evalHalfPlane(v0, v1, v2, 0, 0);
    *dy = evalHalfPlane(v0, v1, v2, 0, 1) - evalHalfPlane(v0, v1, v2, 0, 0);
}

void triRast(float v0[2], float v1[2], float v2[2], int viewport[4],
    void *data, pixelFunc doPixel)
{
    int bbox[4];
    int i, j;
    float bary[3];
    float dxa, dxb, dxc;
    float dya, dyb, dyc;
    float rowa, rowb, rowc;

    boxi2DClear(bbox);
    boxi2DGrow(bbox, v0);
    boxi2DGrow(bbox, v1);
    boxi2DGrow(bbox, v2);
    boxi2DIsect(bbox, viewport, bbox);

    calcHalfPlaneDiffs(v1, v2, v0, &dxa, &dya);
    rowa = evalHalfPlane(v1, v2, v0, bbox[0] + 0.5f, bbox[2] + 0.5f);

    calcHalfPlaneDiffs(v2, v0, v1, &dxb, &dyb);
    rowb = evalHalfPlane(v2, v0, v1, bbox[0] + 0.5f, bbox[2] + 0.5f);

    calcHalfPlaneDiffs(v0, v1, v2, &dxc, &dyc);
    rowc = evalHalfPlane(v0, v1, v2, bbox[0] + 0.5f, bbox[2] + 0.5f);

    for(j = bbox[2]; j < bbox[3]; j++) {
        bary[0] = rowa;
        bary[1] = rowb;
        bary[2] = rowc;
	for(i = bbox[0]; i < bbox[1]; i++) {
	    if((bary[0] > -0.001 && bary[0] < 1.001f) &&
	        (bary[1] > -0.001 && bary[1] < 1.001f) &&
	        (bary[2] > -0.001 && bary[2] < 1.001f))
		    doPixel(i, j, bary, data);
	    bary[0] += dxa;
	    bary[1] += dxb;
	    bary[2] += dxc;
	}
	rowa += dya;
	rowb += dyb;
	rowc += dyc;
    }
}

void pixel(int x, int y, float bary[3], void *data)
{
    screen_vertex *s = (screen_vertex *)data;

    if(pattern_enabled) {
        int px = x % 16;
        int py = y % 16;
        if(!(the_pattern[py] & (1 << px)))
            return;
    }

    uint8_t r = bary[0] * s[0].r + bary[1] * s[1].r + bary[2] * s[2].r;
    uint8_t g = bary[0] * s[0].g + bary[1] * s[1].g + bary[2] * s[2].g;
    uint8_t b = bary[0] * s[0].b + bary[1] * s[1].b + bary[2] * s[2].b;
    uint32_t z_ = (bary[0] * s[0].z + bary[1] * s[1].z + bary[2] * s[2].z);

    z_t z = z_ >> Z_SHIFT;

    if(!zbuffer_enabled || (z < pixel_depths[480 - 1 - y][x])) {
        pixel_colors[480 - 1 - y][x][0] = r;
        pixel_colors[480 - 1 - y][x][1] = g;
        pixel_colors[480 - 1 - y][x][2] = b;
        pixel_depths[480 - 1 - y][x] = z;
    }
}

void rasterizer_clear(uint8_t r, uint8_t g, uint8_t b)
{
    for(int j = 0; j < 480; j++)
        for(int i = 0; i < 800; i++) {
            pixel_colors[j][i][0] = r;
            pixel_colors[j][i][1] = g;
            pixel_colors[j][i][2] = b;
        }
}

void rasterizer_linewidth(float w)
{
    the_linewidth = w;
}

void rasterizer_setpattern(uint16_t pattern[16])
{
    for (int i = 0; i < 16; i++) {
        the_pattern[i] = pattern[i];
    }
}

void rasterizer_pattern(int enable)
{
    pattern_enabled = enable;
}

void rasterizer_swap()
{
    static int frame = 0;

    if(hwfb != NULL) {

	memcpy(hwfb, pixel_colors, XMAXSCREEN * YMAXSCREEN * 4);

    } else {

	char name[128];
	sprintf(name, "frame%04d.ppm", frame);
	FILE *fp = fopen(name, "wb");
	fprintf(fp, "P6 800 480 255\n");
        for(int j = 0; j < 480; j++) {
            for(int i = 0; i < 800; i++) {
                fwrite(pixel_colors[j][i], 1, 3, fp);
            }
        }
	fclose(fp);
    }

    frame++;
}

int32_t rasterizer_winopen(char *title)
{
    if(getenv("USE_FRAMEBUFFER") != NULL) {
        int dev_mem = open("/dev/mem", O_RDWR);

        if(dev_mem == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

	hwfb = (unsigned char *)mmap(0, YMAXSCREEN * XMAXSCREEN * 4, PROT_READ | PROT_WRITE, /* MAP_NOCACHE | */ MAP_SHARED , dev_mem, 0x38000000);

	if(hwfb == MAP_FAILED) {
	    perror("mmap");
	    exit(EXIT_FAILURE);
	}
    }

    rasterizer_clear(0, 0, 0);
    rasterizer_zclear(0xffffffff);
    if(getenv("SNAP_VERTICES") != NULL) {
        snap_vertices = 1;
        printf("Vertex values in X and Y will be rounded to nearest pixel corner\n");
    }
    return 1;
}

void rasterizer_zbuffer(int enable)
{
    zbuffer_enabled = enable;
}

void rasterizer_zclear(uint32_t z)
{
    z = 0xffff; // XXX fpgasim does this
    for(int j = 0; j < 480; j++)
        for(int i = 0; i < 800; i++)
            pixel_depths[j][i] = z;
}

void rasterizer_czclear(uint8_t r, uint8_t g, uint8_t b, uint32_t z)
{
    rasterizer_zclear(z);
    rasterizer_clear(r, g, b);
}

void screen_vertex_offset_with_clamp(screen_vertex* v, float dx, float dy)
{
    v->x = clamp(v->x + dx * SCREEN_VERTEX_V2_SCALE, 0, (DISPLAY_WIDTH - 1) * SCREEN_VERTEX_V2_SCALE);
    v->y = clamp(v->y + dy * SCREEN_VERTEX_V2_SCALE, 0, (DISPLAY_HEIGHT - 1) * SCREEN_VERTEX_V2_SCALE);
}

static void draw_screen_triangle(screen_vertex *s0, screen_vertex *s1, screen_vertex *s2)
{
    float v0[2];
    float v1[2];
    float v2[2];
    v0[0] = s0->x / (float)SCREEN_VERTEX_V2_SCALE;
    v0[1] = s0->y / (float)SCREEN_VERTEX_V2_SCALE;
    v1[0] = s1->x / (float)SCREEN_VERTEX_V2_SCALE;
    v1[1] = s1->y / (float)SCREEN_VERTEX_V2_SCALE;
    v2[0] = s2->x / (float)SCREEN_VERTEX_V2_SCALE;
    v2[1] = s2->y / (float)SCREEN_VERTEX_V2_SCALE;
    if(snap_vertices) {
        v0[0] = floor(v0[0]);
        v0[1] = floor(v0[1]);
        v1[0] = floor(v1[0]);
        v1[1] = floor(v1[1]);
        v2[0] = floor(v2[0]);
        v2[1] = floor(v2[1]);
    }
    static int viewport[4] = {0, 0, 800, 480};
    screen_vertex s[3];
    s[0] = *s0;
    s[1] = *s1;
    s[2] = *s2;
    triRast(v0, v1, v2, viewport, s, pixel);
}


// In hardware may have to repack to do FPGA's rowbytes
void rasterizer_bitmap(uint32_t width, uint32_t rowbytes, uint32_t height, screen_vertex *sv, uint8_t *bits)
{
    screen_vertex s[4];

    for(int j = 0; j < height; j++) {
        int prevbit = 0;
        int count;
        for(int i = 0; i < width; i++) {
            int bit = (bits[j * rowbytes + i / 8] >> (7 - i % 8)) & 1;

            if(bit) {

                if(!prevbit && bit) {
                    // Previous bit was 0 and this bit is 1, so start a
                    // run
                    for(int k = 0; k < 4; k++) {
                        s[k] = *sv; // Copy color
                        s[k].x = sv->x + SCREEN_VERTEX_V2_SCALE * i;
                        s[k].y = sv->y + (height - j - 1) * SCREEN_VERTEX_V2_SCALE;
                        s[k].z = sv->z;
                    }

                    screen_vertex_offset_with_clamp(&s[0], 0, 0);
                    screen_vertex_offset_with_clamp(&s[1], 0, 1);
                    count = 0;
                }

                // Add this bit to current run
                count++;

            } else if(prevbit) {

                // The previous bit was 1 and this bit is 0, so
                // finish the run
                screen_vertex_offset_with_clamp(&s[2], count, 1);
                screen_vertex_offset_with_clamp(&s[3], count, 0);
// XXX rasterizer_draw()
                draw_screen_triangle(&s[0], &s[1], &s[2]);
                draw_screen_triangle(&s[2], &s[3], &s[0]);
            }

            prevbit = bit;
        }

        if(prevbit) {
            // the end of the row was a 1 bit, so finish run
            screen_vertex_offset_with_clamp(&s[2], count, 1);
            screen_vertex_offset_with_clamp(&s[3], count, 0);
// XXX rasterizer_draw()
            draw_screen_triangle(&s[0], &s[1], &s[2]);
            draw_screen_triangle(&s[2], &s[3], &s[0]);
        }
    }
}

void draw_line(screen_vertex *v0, screen_vertex *v1)
{
    if(1) {
        float dx = (v1->x - v0->x);
        float dy = (v1->y - v0->y);
        float d = sqrt(dx * dx + dy * dy);

        if(d == 0.0) {
            // XXX should draw point if the line is too short
            return;
        }

        screen_vertex q[4];
        q[0] = *v0;
        q[1] = *v0;
        q[2] = *v1;
        q[3] = *v1;

        if(fabs(dx) > fabs(dy)) {
            screen_vertex_offset_with_clamp(&q[0], 0, -the_linewidth * .5);
            screen_vertex_offset_with_clamp(&q[1], 0,  the_linewidth * .5);
            screen_vertex_offset_with_clamp(&q[2], 0,  the_linewidth * .5);
            screen_vertex_offset_with_clamp(&q[3], 0, -the_linewidth * .5);
        } else {
            screen_vertex_offset_with_clamp(&q[0], -the_linewidth * .5, 0);
            screen_vertex_offset_with_clamp(&q[1],  the_linewidth * .5, 0);
            screen_vertex_offset_with_clamp(&q[2],  the_linewidth * .5, 0);
            screen_vertex_offset_with_clamp(&q[3], -the_linewidth * .5, 0);
        }

        draw_screen_triangle(&q[0], &q[1], &q[2]);
        draw_screen_triangle(&q[2], &q[3], &q[0]);

    } else {
        // XXX Ignores line width

        int dx = (v1->x - v0->x) * 256 / SCREEN_VERTEX_V2_SCALE;
        int dy = (v1->y - v0->y) * 256 / SCREEN_VERTEX_V2_SCALE;

        if(abs(dx) > abs(dy)) {

            int dp = (v0->x < v1->x) ? 1 : -1;
            int count = abs(v1->x / SCREEN_VERTEX_V2_SCALE - v0->x / SCREEN_VERTEX_V2_SCALE);
            int x = v0->x / SCREEN_VERTEX_V2_SCALE;
            int y = v0->y * 256 / SCREEN_VERTEX_V2_SCALE;
            for(int i = 0; i < count; i++) {
                for(int j = 0; j <= the_linewidth; j++) {
                    int k = (y - 256 * the_linewidth / 2) / 256 + j;
                    pixel_colors[480 - 1 - k][x][0] = 255;
                    pixel_colors[480 - 1 - k][x][1] = 255;
                    pixel_colors[480 - 1 - k][x][2] = 255;
                }
                y += dy/count;
                x += dp;
            }

        } else {

            int dp = (v0->y < v1->y) ? 1 : -1;
            int count = abs(v1->y / SCREEN_VERTEX_V2_SCALE - v0->y / SCREEN_VERTEX_V2_SCALE);
            int x = v0->x * 256 / SCREEN_VERTEX_V2_SCALE;
            int y = v0->y / SCREEN_VERTEX_V2_SCALE;
            for(int i = 0; i < count; i++) {
                for(int j = 0; j <= the_linewidth; j++) {
                    int k = (x - 256 * the_linewidth / 2) / 256 + j;
                    pixel_colors[480 - 1 - y][k][0] = 255;
                    pixel_colors[480 - 1 - y][k][1] = 255;
                    pixel_colors[480 - 1 - y][k][2] = 255;
                }
                y += dp;
                x += dx/count;
            }
        }
    }
}

void rasterizer_draw(uint32_t type, uint32_t count, screen_vertex *screenverts)
{
    switch(type) {
        case DRAW_POINTS:
            fprintf(stderr, "POINTS not implemented\n");
            break;
        case DRAW_LINES:
            for(int i = 0; i < count / 2; i++) { 
                draw_line(&screenverts[i * 2 + 0], &screenverts[i * 2 + 1]);
            }
            break;
        case DRAW_TRIANGLES:
            for(int i = 0; i < count / 3; i++)
                draw_screen_triangle(&screenverts[i * 3], &screenverts[i * 3 + 1], &screenverts[i * 3 + 2]);
            break;
    }
}

