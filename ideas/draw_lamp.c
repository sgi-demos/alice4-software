#include <gl.h>

#include "objects.h"

float hp[6][13][3] = {

    {
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
    },
    {
	{0.438371, 0.000000, 0.898794},
	{0.379641, 0.219186, 0.898794},
	{0.219186, 0.379641, 0.898794},
	{0.000000, 0.438371, 0.898794},
	{-0.219186, 0.379641, 0.898794},
	{-0.379641, 0.219186, 0.898794},
	{-0.438371, 0.000000, 0.898794},
	{-0.379641, -0.219186, 0.898794},
	{-0.219186, -0.379641, 0.898794},
	{0.000000, -0.438371, 0.898794},
	{0.219186, -0.379641, 0.898794},
	{0.379641, -0.219186, 0.898794},
	{0.438371, 0.000000, 0.898794},
    },
    {
	{0.788011, 0.000000, 0.615662},
	{0.682437, 0.394005, 0.615662},
	{0.394005, 0.682437, 0.615662},
	{0.000000, 0.788011, 0.615662},
	{-0.394005, 0.682437, 0.615662},
	{-0.682437, 0.394005, 0.615662},
	{-0.788011, 0.000000, 0.615662},
	{-0.682437, -0.394005, 0.615662},
	{-0.394005, -0.682437, 0.615662},
	{0.000000, -0.788011, 0.615662},
	{0.394005, -0.682437, 0.615662},
	{0.682437, -0.394005, 0.615662},
	{0.788011, 0.000000, 0.615662},
    },
    {
	{0.978148, 0.000000, 0.207912},
	{0.847101, 0.489074, 0.207912},
	{0.489074, 0.847101, 0.207912},
	{0.000000, 0.978148, 0.207912},
	{-0.489074, 0.847101, 0.207912},
	{-0.847101, 0.489074, 0.207912},
	{-0.978148, 0.000000, 0.207912},
	{-0.847101, -0.489074, 0.207912},
	{-0.489074, -0.847101, 0.207912},
	{0.000000, -0.978148, 0.207912},
	{0.489074, -0.847101, 0.207912},
	{0.847101, -0.489074, 0.207912},
	{0.978148, 0.000000, 0.207912},
    },
    {
	{0.970296, 0.000000, -0.241922},
	{0.840301, 0.485148, -0.241922},
	{0.485148, 0.840301, -0.241922},
	{0.000000, 0.970296, -0.241922},
	{-0.485148, 0.840301, -0.241922},
	{-0.840301, 0.485148, -0.241922},
	{-0.970296, 0.000000, -0.241922},
	{-0.840301, -0.485148, -0.241922},
	{-0.485148, -0.840301, -0.241922},
	{0.000000, -0.970296, -0.241922},
	{0.485148, -0.840301, -0.241922},
	{0.840301, -0.485148, -0.241922},
	{0.970296, 0.000000, -0.241922},
    },
    {
	{0.766044, 0.000000, -0.642788},
	{0.663414, 0.383022, -0.642788},
	{0.383022, 0.663414, -0.642788},
	{0.000000, 0.766044, -0.642788},
	{-0.383022, 0.663414, -0.642788},
	{-0.663414, 0.383022, -0.642788},
	{-0.766044, 0.000000, -0.642788},
	{-0.663414, -0.383022, -0.642788},
	{-0.383022, -0.663414, -0.642788},
	{0.000000, -0.766044, -0.642788},
	{0.383022, -0.663414, -0.642788},
	{0.663414, -0.383022, -0.642788},
	{0.766044, 0.000000, -0.642788},
    },
};

float ltp[9][25][3] = {
     {
	{10.000000, 0.000000, 1.000000},
	{9.659258, -2.588191, 1.000000},
	{8.660254, -5.000000, 1.000000},
	{7.071068, -7.071068, 1.000000},
	{5.000000, -8.660254, 1.000000},
	{2.588191, -9.659258, 1.000000},
	{0.000000, -10.000000, 1.000000},
	{-2.588191, -9.659258, 1.000000},
	{-5.000000, -8.660254, 1.000000},
	{-7.071068, -7.071068, 1.000000},
	{-8.660254, -5.000000, 1.000000},
	{-9.659258, -2.588191, 1.000000},
	{-10.000000, 0.000000, 1.000000},
	{-9.659258, 2.588191, 1.000000},
	{-8.660254, 5.000000, 1.000000},
	{-7.071068, 7.071068, 1.000000},
	{-5.000000, 8.660254, 1.000000},
	{-2.588191, 9.659258, 1.000000},
	{0.000000, 10.000000, 1.000000},
	{2.588191, 9.659258, 1.000000},
	{5.000000, 8.660254, 1.000000},
	{7.071068, 7.071068, 1.000000},
	{8.660254, 5.000000, 1.000000},
	{9.659258, 2.588191, 1.000000},
	{10.000000, 0.000000, 1.000000},
    },

     {
	{10.707107, 0.000000, 0.707107},
	{10.342271, -2.771203, 0.707107},
	{9.272627, -5.353553, 0.707107},
	{7.571068, -7.571068, 0.707107},
	{5.353553, -9.272627, 0.707107},
	{2.771203, -10.342271, 0.707107},
	{0.000000, -10.707107, 0.707107},
	{-2.771203, -10.342271, 0.707107},
	{-5.353553, -9.272627, 0.707107},
	{-7.571068, -7.571068, 0.707107},
	{-9.272627, -5.353553, 0.707107},
	{-10.342271, -2.771203, 0.707107},
	{-10.707107, 0.000000, 0.707107},
	{-10.342271, 2.771203, 0.707107},
	{-9.272627, 5.353553, 0.707107},
	{-7.571068, 7.571068, 0.707107},
	{-5.353553, 9.272627, 0.707107},
	{-2.771203, 10.342271, 0.707107},
	{0.000000, 10.707107, 0.707107},
	{2.771203, 10.342271, 0.707107},
	{5.353553, 9.272627, 0.707107},
	{7.571068, 7.571068, 0.707107},
	{9.272627, 5.353553, 0.707107},
	{10.342271, 2.771203, 0.707107},
	{10.707107, 0.000000, 0.707107},
    },

     {
	{11.000000, 0.000000, 0.000000},
	{10.625184, -2.847009, 0.000000},
	{9.526279, -5.500000, 0.000000},
	{7.778174, -7.778174, 0.000000},
	{5.500000, -9.526279, 0.000000},
	{2.847009, -10.625184, 0.000000},
	{0.000000, -11.000000, 0.000000},
	{-2.847009, -10.625184, 0.000000},
	{-5.500000, -9.526279, 0.000000},
	{-7.778174, -7.778174, 0.000000},
	{-9.526279, -5.500000, 0.000000},
	{-10.625184, -2.847009, 0.000000},
	{-11.000000, 0.000000, 0.000000},
	{-10.625184, 2.847009, 0.000000},
	{-9.526279, 5.500000, 0.000000},
	{-7.778174, 7.778174, 0.000000},
	{-5.500000, 9.526279, 0.000000},
	{-2.847009, 10.625184, 0.000000},
	{0.000000, 11.000000, 0.000000},
	{2.847009, 10.625184, 0.000000},
	{5.500000, 9.526279, 0.000000},
	{7.778174, 7.778174, 0.000000},
	{9.526279, 5.500000, 0.000000},
	{10.625184, 2.847009, 0.000000},
	{11.000000, 0.000000, 0.000000},
    },

     {
	{10.707107, 0.000000, -0.707107},
	{10.342271, -2.771203, -0.707107},
	{9.272627, -5.353553, -0.707107},
	{7.571068, -7.571068, -0.707107},
	{5.353553, -9.272627, -0.707107},
	{2.771203, -10.342271, -0.707107},
	{0.000000, -10.707107, -0.707107},
	{-2.771203, -10.342271, -0.707107},
	{-5.353553, -9.272627, -0.707107},
	{-7.571068, -7.571068, -0.707107},
	{-9.272627, -5.353553, -0.707107},
	{-10.342271, -2.771203, -0.707107},
	{-10.707107, 0.000000, -0.707107},
	{-10.342271, 2.771203, -0.707107},
	{-9.272627, 5.353553, -0.707107},
	{-7.571068, 7.571068, -0.707107},
	{-5.353553, 9.272627, -0.707107},
	{-2.771203, 10.342271, -0.707107},
	{0.000000, 10.707107, -0.707107},
	{2.771203, 10.342271, -0.707107},
	{5.353553, 9.272627, -0.707107},
	{7.571068, 7.571068, -0.707107},
	{9.272627, 5.353553, -0.707107},
	{10.342271, 2.771203, -0.707107},
	{10.707107, 0.000000, -0.707107},
    },

     {
	{10.000000, 0.000000, -1.000000},
	{9.659258, -2.588191, -1.000000},
	{8.660254, -5.000000, -1.000000},
	{7.071068, -7.071068, -1.000000},
	{5.000000, -8.660254, -1.000000},
	{2.588191, -9.659258, -1.000000},
	{0.000000, -10.000000, -1.000000},
	{-2.588191, -9.659258, -1.000000},
	{-5.000000, -8.660254, -1.000000},
	{-7.071068, -7.071068, -1.000000},
	{-8.660254, -5.000000, -1.000000},
	{-9.659258, -2.588191, -1.000000},
	{-10.000000, 0.000000, -1.000000},
	{-9.659258, 2.588191, -1.000000},
	{-8.660254, 5.000000, -1.000000},
	{-7.071068, 7.071068, -1.000000},
	{-5.000000, 8.660254, -1.000000},
	{-2.588191, 9.659258, -1.000000},
	{0.000000, 10.000000, -1.000000},
	{2.588191, 9.659258, -1.000000},
	{5.000000, 8.660254, -1.000000},
	{7.071068, 7.071068, -1.000000},
	{8.660254, 5.000000, -1.000000},
	{9.659258, 2.588191, -1.000000},
	{10.000000, 0.000000, -1.000000},
    },

     {
	{9.292893, 0.000000, -0.707107},
	{8.976246, -2.405178, -0.707107},
	{8.047881, -4.646447, -0.707107},
	{6.571068, -6.571068, -0.707107},
	{4.646447, -8.047881, -0.707107},
	{2.405178, -8.976246, -0.707107},
	{0.000000, -9.292893, -0.707107},
	{-2.405178, -8.976246, -0.707107},
	{-4.646447, -8.047881, -0.707107},
	{-6.571068, -6.571068, -0.707107},
	{-8.047881, -4.646447, -0.707107},
	{-8.976246, -2.405178, -0.707107},
	{-9.292893, 0.000000, -0.707107},
	{-8.976246, 2.405178, -0.707107},
	{-8.047881, 4.646447, -0.707107},
	{-6.571068, 6.571068, -0.707107},
	{-4.646447, 8.047881, -0.707107},
	{-2.405178, 8.976246, -0.707107},
	{0.000000, 9.292893, -0.707107},
	{2.405178, 8.976246, -0.707107},
	{4.646447, 8.047881, -0.707107},
	{6.571068, 6.571068, -0.707107},
	{8.047881, 4.646447, -0.707107},
	{8.976246, 2.405178, -0.707107},
	{9.292893, 0.000000, -0.707107},
    },

     {
	{9.000000, 0.000000, 0.000000},
	{8.693333, -2.329371, 0.000000},
	{7.794229, -4.500000, 0.000000},
	{6.363961, -6.363961, 0.000000},
	{4.500000, -7.794229, 0.000000},
	{2.329371, -8.693333, 0.000000},
	{0.000000, -9.000000, 0.000000},
	{-2.329371, -8.693333, 0.000000},
	{-4.500000, -7.794229, 0.000000},
	{-6.363961, -6.363961, 0.000000},
	{-7.794229, -4.500000, 0.000000},
	{-8.693333, -2.329371, 0.000000},
	{-9.000000, 0.000000, 0.000000},
	{-8.693333, 2.329371, 0.000000},
	{-7.794229, 4.500000, 0.000000},
	{-6.363961, 6.363961, 0.000000},
	{-4.500000, 7.794229, 0.000000},
	{-2.329371, 8.693333, 0.000000},
	{0.000000, 9.000000, 0.000000},
	{2.329371, 8.693333, 0.000000},
	{4.500000, 7.794229, 0.000000},
	{6.363961, 6.363961, 0.000000},
	{7.794229, 4.500000, 0.000000},
	{8.693333, 2.329371, 0.000000},
	{9.000000, 0.000000, 0.000000},
    },

     {
	{9.292893, 0.000000, 0.707107},
	{8.976246, -2.405178, 0.707107},
	{8.047881, -4.646447, 0.707107},
	{6.571068, -6.571068, 0.707107},
	{4.646447, -8.047881, 0.707107},
	{2.405178, -8.976246, 0.707107},
	{0.000000, -9.292893, 0.707107},
	{-2.405178, -8.976246, 0.707107},
	{-4.646447, -8.047881, 0.707107},
	{-6.571068, -6.571068, 0.707107},
	{-8.047881, -4.646447, 0.707107},
	{-8.976246, -2.405178, 0.707107},
	{-9.292893, 0.000000, 0.707107},
	{-8.976246, 2.405178, 0.707107},
	{-8.047881, 4.646447, 0.707107},
	{-6.571068, 6.571068, 0.707107},
	{-4.646447, 8.047881, 0.707107},
	{-2.405178, 8.976246, 0.707107},
	{0.000000, 9.292893, 0.707107},
	{2.405178, 8.976246, 0.707107},
	{4.646447, 8.047881, 0.707107},
	{6.571068, 6.571068, 0.707107},
	{8.047881, 4.646447, 0.707107},
	{8.976246, 2.405178, 0.707107},
	{9.292893, 0.000000, 0.707107},
    },

     {
	{10.000000, 0.000000, 1.000000},
	{9.659258, -2.588191, 1.000000},
	{8.660254, -5.000000, 1.000000},
	{7.071068, -7.071068, 1.000000},
	{5.000000, -8.660254, 1.000000},
	{2.588191, -9.659258, 1.000000},
	{0.000000, -10.000000, 1.000000},
	{-2.588191, -9.659258, 1.000000},
	{-5.000000, -8.660254, 1.000000},
	{-7.071068, -7.071068, 1.000000},
	{-8.660254, -5.000000, 1.000000},
	{-9.659258, -2.588191, 1.000000},
	{-10.000000, 0.000000, 1.000000},
	{-9.659258, 2.588191, 1.000000},
	{-8.660254, 5.000000, 1.000000},
	{-7.071068, 7.071068, 1.000000},
	{-5.000000, 8.660254, 1.000000},
	{-2.588191, 9.659258, 1.000000},
	{0.000000, 10.000000, 1.000000},
	{2.588191, 9.659258, 1.000000},
	{5.000000, 8.660254, 1.000000},
	{7.071068, 7.071068, 1.000000},
	{8.660254, 5.000000, 1.000000},
	{9.659258, 2.588191, 1.000000},
	{10.000000, 0.000000, 1.000000},
    },

};

float ltn[9][25][3] = {
    {
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
    },

    {
	{0.707107, 0.000000, 0.707107},
	{0.683013, -0.183013, 0.707107},
	{0.612372, -0.353553, 0.707107},
	{0.500000, -0.500000, 0.707107},
	{0.353553, -0.612372, 0.707107},
	{0.183013, -0.683013, 0.707107},
	{0.000000, -0.707107, 0.707107},
	{-0.183013, -0.683013, 0.707107},
	{-0.353553, -0.612372, 0.707107},
	{-0.500000, -0.500000, 0.707107},
	{-0.612372, -0.353553, 0.707107},
	{-0.683013, -0.183013, 0.707107},
	{-0.707107, 0.000000, 0.707107},
	{-0.683013, 0.183013, 0.707107},
	{-0.612372, 0.353553, 0.707107},
	{-0.500000, 0.500000, 0.707107},
	{-0.353553, 0.612372, 0.707107},
	{-0.183013, 0.683013, 0.707107},
	{0.000000, 0.707107, 0.707107},
	{0.183013, 0.683013, 0.707107},
	{0.353553, 0.612372, 0.707107},
	{0.500000, 0.500000, 0.707107},
	{0.612372, 0.353553, 0.707107},
	{0.683013, 0.183013, 0.707107},
	{0.707107, 0.000000, 0.707107},
    },

    {
	{1.000000, 0.000000, 0.000000},
	{0.965926, -0.258819, 0.000000},
	{0.866025, -0.500000, 0.000000},
	{0.707107, -0.707107, 0.000000},
	{0.500000, -0.866025, 0.000000},
	{0.258819, -0.965926, 0.000000},
	{0.000000, -1.000000, 0.000000},
	{-0.258819, -0.965926, 0.000000},
	{-0.500000, -0.866025, 0.000000},
	{-0.707107, -0.707107, 0.000000},
	{-0.866025, -0.500000, 0.000000},
	{-0.965926, -0.258819, 0.000000},
	{-1.000000, 0.000000, 0.000000},
	{-0.965926, 0.258819, 0.000000},
	{-0.866025, 0.500000, 0.000000},
	{-0.707107, 0.707107, 0.000000},
	{-0.500000, 0.866025, 0.000000},
	{-0.258819, 0.965926, 0.000000},
	{0.000000, 1.000000, 0.000000},
	{0.258819, 0.965926, 0.000000},
	{0.500000, 0.866025, 0.000000},
	{0.707107, 0.707107, 0.000000},
	{0.866025, 0.500000, 0.000000},
	{0.965926, 0.258819, 0.000000},
	{1.000000, 0.000000, 0.000000},
    },

    {
	{0.707107, 0.000000, -0.707107},
	{0.683013, -0.183013, -0.707107},
	{0.612372, -0.353553, -0.707107},
	{0.500000, -0.500000, -0.707107},
	{0.353553, -0.612372, -0.707107},
	{0.183013, -0.683013, -0.707107},
	{0.000000, -0.707107, -0.707107},
	{-0.183013, -0.683013, -0.707107},
	{-0.353553, -0.612372, -0.707107},
	{-0.500000, -0.500000, -0.707107},
	{-0.612372, -0.353553, -0.707107},
	{-0.683013, -0.183013, -0.707107},
	{-0.707107, 0.000000, -0.707107},
	{-0.683013, 0.183013, -0.707107},
	{-0.612372, 0.353553, -0.707107},
	{-0.500000, 0.500000, -0.707107},
	{-0.353553, 0.612372, -0.707107},
	{-0.183013, 0.683013, -0.707107},
	{0.000000, 0.707107, -0.707107},
	{0.183013, 0.683013, -0.707107},
	{0.353553, 0.612372, -0.707107},
	{0.500000, 0.500000, -0.707107},
	{0.612372, 0.353553, -0.707107},
	{0.683013, 0.183013, -0.707107},
	{0.707107, 0.000000, -0.707107},
    },

    {
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
	{0.000000, 0.000000, -1.000000},
    },

    {
	{-0.707107, 0.000000, -0.707107},
	{-0.683013, 0.183013, -0.707107},
	{-0.612372, 0.353553, -0.707107},
	{-0.500000, 0.500000, -0.707107},
	{-0.353553, 0.612372, -0.707107},
	{-0.183013, 0.683013, -0.707107},
	{0.000000, 0.707107, -0.707107},
	{0.183013, 0.683013, -0.707107},
	{0.353553, 0.612372, -0.707107},
	{0.500000, 0.500000, -0.707107},
	{0.612372, 0.353553, -0.707107},
	{0.683013, 0.183013, -0.707107},
	{0.707107, 0.000000, -0.707107},
	{0.683013, -0.183013, -0.707107},
	{0.612372, -0.353553, -0.707107},
	{0.500000, -0.500000, -0.707107},
	{0.353553, -0.612372, -0.707107},
	{0.183013, -0.683013, -0.707107},
	{0.000000, -0.707107, -0.707107},
	{-0.183013, -0.683013, -0.707107},
	{-0.353553, -0.612372, -0.707107},
	{-0.500000, -0.500000, -0.707107},
	{-0.612372, -0.353553, -0.707107},
	{-0.683013, -0.183013, -0.707107},
	{-0.707107, 0.000000, -0.707107},
    },

    {
	{-1.000000, 0.000000, 0.000000},
	{-0.965926, 0.258819, 0.000000},
	{-0.866025, 0.500000, 0.000000},
	{-0.707107, 0.707107, 0.000000},
	{-0.500000, 0.866025, 0.000000},
	{-0.258819, 0.965926, 0.000000},
	{0.000000, 1.000000, 0.000000},
	{0.258819, 0.965926, 0.000000},
	{0.500000, 0.866025, 0.000000},
	{0.707107, 0.707107, 0.000000},
	{0.866025, 0.500000, 0.000000},
	{0.965926, 0.258819, 0.000000},
	{1.000000, 0.000000, 0.000000},
	{0.965926, -0.258819, 0.000000},
	{0.866025, -0.500000, 0.000000},
	{0.707107, -0.707107, 0.000000},
	{0.500000, -0.866025, 0.000000},
	{0.258819, -0.965926, 0.000000},
	{0.000000, -1.000000, 0.000000},
	{-0.258819, -0.965926, 0.000000},
	{-0.500000, -0.866025, 0.000000},
	{-0.707107, -0.707107, 0.000000},
	{-0.866025, -0.500000, 0.000000},
	{-0.965926, -0.258819, 0.000000},
	{-1.000000, 0.000000, 0.000000},
    },

    {
	{-0.707107, 0.000000, 0.707107},
	{-0.683013, 0.183013, 0.707107},
	{-0.612372, 0.353553, 0.707107},
	{-0.500000, 0.500000, 0.707107},
	{-0.353553, 0.612372, 0.707107},
	{-0.183013, 0.683013, 0.707107},
	{0.000000, 0.707107, 0.707107},
	{0.183013, 0.683013, 0.707107},
	{0.353553, 0.612372, 0.707107},
	{0.500000, 0.500000, 0.707107},
	{0.612372, 0.353553, 0.707107},
	{0.683013, 0.183013, 0.707107},
	{0.707107, 0.000000, 0.707107},
	{0.683013, -0.183013, 0.707107},
	{0.612372, -0.353553, 0.707107},
	{0.500000, -0.500000, 0.707107},
	{0.353553, -0.612372, 0.707107},
	{0.183013, -0.683013, 0.707107},
	{0.000000, -0.707107, 0.707107},
	{-0.183013, -0.683013, 0.707107},
	{-0.353553, -0.612372, 0.707107},
	{-0.500000, -0.500000, 0.707107},
	{-0.612372, -0.353553, 0.707107},
	{-0.683013, -0.183013, 0.707107},
	{-0.707107, 0.000000, 0.707107},
    },

    {
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
	{0.000000, 0.000000, 1.000000},
    },

};

draw_hemisphere() {

	lmbind(MATERIAL, MAT_HEMISPHERE);
	lmbind(LMODEL, 1);

	bgntmesh();
	    n3f(hp[0][0]); v3f(hp[0][0]);
	    n3f(hp[1][0]); v3f(hp[1][0]);
	    n3f(hp[0][1]); v3f(hp[0][1]);
	    n3f(hp[1][1]); v3f(hp[1][1]);
	    n3f(hp[0][2]); v3f(hp[0][2]);
	    n3f(hp[1][2]); v3f(hp[1][2]);
	    n3f(hp[0][3]); v3f(hp[0][3]);
	    n3f(hp[1][3]); v3f(hp[1][3]);
	    n3f(hp[0][4]); v3f(hp[0][4]);
	    n3f(hp[1][4]); v3f(hp[1][4]);
	    n3f(hp[0][5]); v3f(hp[0][5]);
	    n3f(hp[1][5]); v3f(hp[1][5]);
	    n3f(hp[0][6]); v3f(hp[0][6]);
	    n3f(hp[1][6]); v3f(hp[1][6]);
	    n3f(hp[0][7]); v3f(hp[0][7]);
	    n3f(hp[1][7]); v3f(hp[1][7]);
	    n3f(hp[0][8]); v3f(hp[0][8]);
	    n3f(hp[1][8]); v3f(hp[1][8]);
	    n3f(hp[0][9]); v3f(hp[0][9]);
	    n3f(hp[1][9]); v3f(hp[1][9]);
	    n3f(hp[0][10]); v3f(hp[0][10]);
	    n3f(hp[1][10]); v3f(hp[1][10]);
	    n3f(hp[0][11]); v3f(hp[0][11]);
	    n3f(hp[1][11]); v3f(hp[1][11]);
	    n3f(hp[0][12]); v3f(hp[0][12]);
	    n3f(hp[1][12]); v3f(hp[1][12]);
	endtmesh();

	bgntmesh();
	    n3f(hp[1][0]); v3f(hp[1][0]);
	    n3f(hp[2][0]); v3f(hp[2][0]);
	    n3f(hp[1][1]); v3f(hp[1][1]);
	    n3f(hp[2][1]); v3f(hp[2][1]);
	    n3f(hp[1][2]); v3f(hp[1][2]);
	    n3f(hp[2][2]); v3f(hp[2][2]);
	    n3f(hp[1][3]); v3f(hp[1][3]);
	    n3f(hp[2][3]); v3f(hp[2][3]);
	    n3f(hp[1][4]); v3f(hp[1][4]);
	    n3f(hp[2][4]); v3f(hp[2][4]);
	    n3f(hp[1][5]); v3f(hp[1][5]);
	    n3f(hp[2][5]); v3f(hp[2][5]);
	    n3f(hp[1][6]); v3f(hp[1][6]);
	    n3f(hp[2][6]); v3f(hp[2][6]);
	    n3f(hp[1][7]); v3f(hp[1][7]);
	    n3f(hp[2][7]); v3f(hp[2][7]);
	    n3f(hp[1][8]); v3f(hp[1][8]);
	    n3f(hp[2][8]); v3f(hp[2][8]);
	    n3f(hp[1][9]); v3f(hp[1][9]);
	    n3f(hp[2][9]); v3f(hp[2][9]);
	    n3f(hp[1][10]); v3f(hp[1][10]);
	    n3f(hp[2][10]); v3f(hp[2][10]);
	    n3f(hp[1][11]); v3f(hp[1][11]);
	    n3f(hp[2][11]); v3f(hp[2][11]);
	    n3f(hp[1][12]); v3f(hp[1][12]);
	    n3f(hp[2][12]); v3f(hp[2][12]);
	endtmesh();

	bgntmesh();
	    n3f(hp[2][0]); v3f(hp[2][0]);
	    n3f(hp[3][0]); v3f(hp[3][0]);
	    n3f(hp[2][1]); v3f(hp[2][1]);
	    n3f(hp[3][1]); v3f(hp[3][1]);
	    n3f(hp[2][2]); v3f(hp[2][2]);
	    n3f(hp[3][2]); v3f(hp[3][2]);
	    n3f(hp[2][3]); v3f(hp[2][3]);
	    n3f(hp[3][3]); v3f(hp[3][3]);
	    n3f(hp[2][4]); v3f(hp[2][4]);
	    n3f(hp[3][4]); v3f(hp[3][4]);
	    n3f(hp[2][5]); v3f(hp[2][5]);
	    n3f(hp[3][5]); v3f(hp[3][5]);
	    n3f(hp[2][6]); v3f(hp[2][6]);
	    n3f(hp[3][6]); v3f(hp[3][6]);
	    n3f(hp[2][7]); v3f(hp[2][7]);
	    n3f(hp[3][7]); v3f(hp[3][7]);
	    n3f(hp[2][8]); v3f(hp[2][8]);
	    n3f(hp[3][8]); v3f(hp[3][8]);
	    n3f(hp[2][9]); v3f(hp[2][9]);
	    n3f(hp[3][9]); v3f(hp[3][9]);
	    n3f(hp[2][10]); v3f(hp[2][10]);
	    n3f(hp[3][10]); v3f(hp[3][10]);
	    n3f(hp[2][11]); v3f(hp[2][11]);
	    n3f(hp[3][11]); v3f(hp[3][11]);
	    n3f(hp[2][12]); v3f(hp[2][12]);
	    n3f(hp[3][12]); v3f(hp[3][12]);
	endtmesh();

	bgntmesh();
	    n3f(hp[3][0]); v3f(hp[3][0]);
	    n3f(hp[4][0]); v3f(hp[4][0]);
	    n3f(hp[3][1]); v3f(hp[3][1]);
	    n3f(hp[4][1]); v3f(hp[4][1]);
	    n3f(hp[3][2]); v3f(hp[3][2]);
	    n3f(hp[4][2]); v3f(hp[4][2]);
	    n3f(hp[3][3]); v3f(hp[3][3]);
	    n3f(hp[4][3]); v3f(hp[4][3]);
	    n3f(hp[3][4]); v3f(hp[3][4]);
	    n3f(hp[4][4]); v3f(hp[4][4]);
	    n3f(hp[3][5]); v3f(hp[3][5]);
	    n3f(hp[4][5]); v3f(hp[4][5]);
	    n3f(hp[3][6]); v3f(hp[3][6]);
	    n3f(hp[4][6]); v3f(hp[4][6]);
	    n3f(hp[3][7]); v3f(hp[3][7]);
	    n3f(hp[4][7]); v3f(hp[4][7]);
	    n3f(hp[3][8]); v3f(hp[3][8]);
	    n3f(hp[4][8]); v3f(hp[4][8]);
	    n3f(hp[3][9]); v3f(hp[3][9]);
	    n3f(hp[4][9]); v3f(hp[4][9]);
	    n3f(hp[3][10]); v3f(hp[3][10]);
	    n3f(hp[4][10]); v3f(hp[4][10]);
	    n3f(hp[3][11]); v3f(hp[3][11]);
	    n3f(hp[4][11]); v3f(hp[4][11]);
	    n3f(hp[3][12]); v3f(hp[3][12]);
	    n3f(hp[4][12]); v3f(hp[4][12]);
	endtmesh();

	bgntmesh();
	    n3f(hp[4][0]); v3f(hp[4][0]);
	    n3f(hp[5][0]); v3f(hp[5][0]);
	    n3f(hp[4][1]); v3f(hp[4][1]);
	    n3f(hp[5][1]); v3f(hp[5][1]);
	    n3f(hp[4][2]); v3f(hp[4][2]);
	    n3f(hp[5][2]); v3f(hp[5][2]);
	    n3f(hp[4][3]); v3f(hp[4][3]);
	    n3f(hp[5][3]); v3f(hp[5][3]);
	    n3f(hp[4][4]); v3f(hp[4][4]);
	    n3f(hp[5][4]); v3f(hp[5][4]);
	    n3f(hp[4][5]); v3f(hp[4][5]);
	    n3f(hp[5][5]); v3f(hp[5][5]);
	    n3f(hp[4][6]); v3f(hp[4][6]);
	    n3f(hp[5][6]); v3f(hp[5][6]);
	    n3f(hp[4][7]); v3f(hp[4][7]);
	    n3f(hp[5][7]); v3f(hp[5][7]);
	    n3f(hp[4][8]); v3f(hp[4][8]);
	    n3f(hp[5][8]); v3f(hp[5][8]);
	    n3f(hp[4][9]); v3f(hp[4][9]);
	    n3f(hp[5][9]); v3f(hp[5][9]);
	    n3f(hp[4][10]); v3f(hp[4][10]);
	    n3f(hp[5][10]); v3f(hp[5][10]);
	    n3f(hp[4][11]); v3f(hp[4][11]);
	    n3f(hp[5][11]); v3f(hp[5][11]);
	    n3f(hp[4][12]); v3f(hp[4][12]);
	    n3f(hp[5][12]); v3f(hp[5][12]);
	endtmesh();

	lmbind(LMODEL, 0);
	RGBcolor(255, 255, 255);
	bgnpolygon();
	    v3f(hp[5][0]);
	    v3f(hp[5][1]);
	    v3f(hp[5][2]);
	    v3f(hp[5][3]);
	    v3f(hp[5][4]);
	    v3f(hp[5][5]);
	    v3f(hp[5][6]);
	    v3f(hp[5][7]);
	    v3f(hp[5][8]);
	    v3f(hp[5][9]);
	    v3f(hp[5][10]);
	    v3f(hp[5][11]);
	endpolygon();
}

