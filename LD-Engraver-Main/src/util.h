/*
 * Util.h  Created on: 11 May 2014
 * Copyright (c) 2014 Derek Molloy (www.derekmolloy.ie)
 * Made available for the book "Exploring BeagleBone" 
 * See: www.exploringbeaglebone.com
 * Licensed under the EUPL V.1.1
 *
 * This Software is provided to You under the terms of the European 
 * Union Public License (the "EUPL") version 1.1 as published by the 
 * European Union. Any use of this Software, other than as authorized 
 * under this License is strictly prohibited (to the extent such use 
 * is covered by a right of the copyright holder of this Software).
 * 
 * This Software is provided under the License on an "AS IS" basis and 
 * without warranties of any kind concerning the Software, including 
 * without limitation merchantability, fitness for a particular purpose, 
 * absence of defects or errors, accuracy, and non-infringement of 
 * intellectual property rights other than copyright. This disclaimer 
 * of warranty is an essential part of the License and a condition for 
 * the grant of any rights to this Software.
 * 
 * For more details, see http://www.derekmolloy.ie/
 */

#ifndef UTIL_H_
#define UTIL_H_
#include<string>
using std::string;



int write(string path, string filename, string value);
int write(string path, string filename, int value);
string read(string path, string filename);

long map(long x, long in_min, long in_max, long out_min, long out_max);
int map(int x, int in_min, int in_max, int out_min, int out_max);

// pour éviter une conversion coûteuse
static unsigned short int volt[256] =
{
	0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 273, 289, 305, 321, 337, 353,
	369, 385, 401, 417, 433, 449, 465, 481, 497, 513, 529, 546, 562, 578, 594, 610, 626, 642, 658,
	674, 690, 706, 722, 738, 754, 770, 786, 802, 819, 835, 851, 867, 883, 899, 915, 931, 947, 963, 979, 995,
	1011, 1027, 1043, 1059, 1075, 1092, 1108, 1124, 1140, 1156, 1172, 1188, 1204, 1220, 1236,
	1252, 1268, 1284, 1300, 1316, 1332, 1348, 1365, 1381, 1397, 1413, 1429, 1445, 1461, 1477, 1493, 1509,
	1525, 1541, 1557, 1573, 1589, 1605, 1621, 1638, 1654, 1670, 1686, 1702, 1718, 1734, 1750,
	1766, 1782, 1798, 1814, 1830, 1846, 1862, 1878, 1894, 1911, 1927, 1943, 1959, 1975, 1991, 2007, 2023,
	2039, 2055, 2071, 2087, 2103, 2119, 2135, 2151, 2167, 2184, 2200, 2216, 2232, 2248, 2264,
	2280, 2296, 2312, 2328, 2344, 2360, 2376, 2392, 2408, 2424, 2440, 2457, 2473, 2489, 2505, 2521, 2537,
	2553, 2569, 2585, 2601, 2617, 2633, 2649, 2665, 2681, 2697, 2713, 2730, 2746, 2762, 2778,
	2794, 2810, 2826, 2842, 2858, 2874, 2890, 2906, 2922, 2938, 2954, 2970, 2986, 3003, 3019, 3035, 3051,
	3067, 3083, 3099, 3115, 3131, 3147, 3163, 3179, 3195, 3211, 3227, 3243, 3259, 3276, 3292,
	3308, 3324, 3340, 3356, 3372, 3388, 3404, 3420, 3436, 3452, 3468, 3484, 3500, 3516, 3532, 3549, 3565,
	3581, 3597, 3613, 3629, 3645, 3661, 3677, 3693, 3709, 3725, 3741, 3757, 3773, 3789, 3805,
	3822, 3838, 3854, 3870, 3886, 3902, 3918, 3934, 3950, 3966, 3982, 3998, 4014, 4030, 4046, 4062, 4078, 4095
};


#endif /* UTIL_H_ */
