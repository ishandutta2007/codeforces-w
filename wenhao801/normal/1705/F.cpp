#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int len = 13;
const int magic[] = {0, 8191,63,448,1536,2048,512,64,128,7,8,16,1,2,63,448,1536,2560,512,1600,2176,128,896,2048,128,128,512,64,128,967,1048,2048,1064,2048,2048,8,473,1570,2048,2050,2,248,1024,2048,296,64,72,128,136,193,258,2,70,256,2,2,64,7,8,16,11,16,13,16,16,1,1,2,63,448,1536,512,2048,1600,128,2752,768,640,128,896,2048,2048,128,1728,2112,64,768,2048,64,64,512,967,1032,16,1040,2048,2048,2048,1496,545,2,2048,2529,520,2,2586,4,8,96,128,64,128,1640,2176,128,2440,128,128,1184,2048,8,72,128,136,505,1026,2048,2050,1218,2308,2244,1,2,64,64,1348,2048,2048,2,64,728,1024,2048,1888,2048,2112,96,8,72,8,72,16,80,128,128,128,193,2,323,68,66,2,70,256,256,2,455,1560,2056,8,544,2048,8,8,512,985,1026,2048,2050,1571,2056,8,6154,2048,2048,557,2048,1,490,1025,2048,3081,1,1024,74,128,64,128,88,8,128,7691,80,128,144,83,128,161,1,401,128,128,1,457,1536,2048,512,1536,2048,512,64,128,64,128,1536,2048,512,65,128,66,128,128,2,7,9,2,10,16,16,16,9,16,10,16,16,2,63,960,192,256,64,1216,1280,64,64,2048,2368,384,384,128,2048,1216,2112,64,1280,2048,2048,64,256,455,1544,528,16,1552,512,2048,2048,2048,1615,144,16,2712,1296,128,1696,8,512,16,512,784,16,2673,128,906,128,128,2702,16,272,88,266,1104,16,16,3607,512,96,128,512,81,2,1,2,760,1025,2,1026,2048,2048,2048,1795,64,1092,1,1,2048,2048,2885,66,66,1,1029,2048,2048,1,1400,2049,2,2050,2115,69,2053,1,2457,2,2088,8,2136,104,2088,8,8,16,1800,2064,16,1040,2048,848,16,64,8,16,1785,2114,68,68,1794,2048,2305,64,64,576,64,576,64,734,64,224,64,2048,264,2,2,512,1,2,455,1544,560,16,2048,2048,2576,544,544,8,16,984,1025,2,1026,2048,2048,2048,1571,8,1036,1,1,2048,2048,2605,10,10,1,1029,2048,2048,1,1512,2049,2,2050,2059,13,2053,1,2289,2,2368,64,2248,80,2368,64,64,128,1632,2176,128,1152,2048,680,8,8,64,128,729,1312,2048,2050,2,2,3299,8,3340,4,2,1024,1024,1306,96,6,4,8,8,1252,2,98,64,64,96,1024,1024,1827,2120,80,80,1100,2048,2128,2050,8,1274,2048,6153,2048,2048,6209,2048,2048,72,8,72,8,1125,8,2049,9,4,2,7241,2,82,1,10,4,1201,2,1,1,2048,3152,1024,1024,1024,2048,72,8,1,249,1536,2048,512,1734,2050,2,514,2,2112,64,576,64,378,1536,2048,512,1604,2048,512,2048,512,1676,2048,512,16,92,8,8,8,16,222,64,72,8,2,10,2,8,16,67,1,69,128,128,128,455,1536,2048,512,2009,2058,12,12,1570,2048,2081,8,8,520,8,520,8,734,8,280,8,2048,96,2,2,512,473,1536,2048,512,1566,2050,2,514,2,2056,8,520,8,490,1536,2048,512,1548,2048,512,2048,512,1620,2048,512,128,204,64,64,64,128,222,8,72,8,2,66,2,64,128,217,296,1536,2048,512,96,10,94,2,282,8,8,8,8,74,12,12,64,128,7,1,2,11,1,13,16,16,16,8,16,127,896,128,256,1024,2048,903,152,288,32,232,256,256,32,8,1464,193,2,1,728,1,2,129,2,1344,8,2048,1096,2048,2504,144,16,2224,16,16,1624,128,8,2056,16,2064,1528,129,2,130,1665,2,2179,2,2182,2,2,2048,2616,1,2,577,2,2120,16,8,16,24,32,8,1027,2048,1029,2048,2048,1,903,24,40,8,1432,1063,8,192,8,545,2,2048,1,2,1577,128,490,128,128,1745,162,2056,2049,2048,2057,8,2048,2216,2368,32,2840,8,8,8,256,1312,8,2176,128,1465,2,1474,8,16,10,16,448,2048,128,1664,2048,1738,16,190,528,18,16,6811,2048,2368,2368,172,1,1,2508,16,18,208,1,724,8,4,4,4,2240,2,2,2777,2,2210,8,8,128,128,4937,2,2306,2306,448,1,1,3247,192,488,128,680,8,1,8,146,2,1768,336,3137,8,728,2048,2328,8,8,808,2048,2048,2064,2056,1768,2048,8,8,8,16,3211,16,32,1172,33,1,2148,1,32,3888,256,256,4,144,1280,1468,449,128,128,2873,4,1621,4,1,2,145,4,18,16,2776,1,1537,1537,1216,8,4,568,2064,144,16,16,5389,16,32,306,17,336,16,505,1,132,306,16,16,16,32,505,2308,133,2308,16,32,140,4,4,393,1,652,1024,1024,1282,1024,505,1152,2048,2176,1154,2048,2180,2,3587,2,128,1,570,1024,2048,1025,2048,12,16,8,16,24,32,8,1,2,911,1024,2048,1969,18,4,20,6163,2052,4,2076,4,4,1046,2048,1,2497,2,4,578,4,5121,128,16,144,1,192,2048,256,1457,2,4,3079,16,4118,2,2,2643,32,34,9,2,1114,1,1,2,2514,1620,1,3086,552,3093,128,196,593,1,1,1,564,16,24,3605,128,2208,2208,560,1,1,2204,16,16,4,4,128,1750,2384,1,1,2520,2,530,201,2,233,2,8,16,1,1834,2048,2208,2208,280,4,2,166,138,194,2,2,1726,1104,2048,304,16,2048,258,4,2,4,128,1459,2048,2492,5,1,1028,1,1,451,16,1,128,192,16,2501,16,2585,8,18,21,1,3605,128,704,156,4,1094,6,6,1780,5,284,1,1,1498,2,784,16,2186,1,1,128,1749,2048,2202,1,1,16,16,2390,1546,6803,1,6,1,678,1,1,1,6299,321,2,611,1,6453,32,2048,2048,2048,2244,1,1,2048,865,2065,470,36,16,196,1180,2048,224,2048,817,2048,1,1380,2048,161,273,1,1,165,1,7,6,5,1,176,16,16,1,497,1024,2048,1414,2050,2,1034,2048,2184,128,128,754,1024,2048,3204,1032,1026,1024,3223,32,1032,1024,180,24,18,16,20,32,36,438,128,184,2,2,16,16,218,20,20,1,24,2,2,16,22,32,26,32,32,2,387,129,1,140,4,4,1,4,911,1027,2052,4,1037,2048,2048,4,1,1971,2064,16,2069,1060,1,2147,32,1,1,1,2088,4,1221,2048,2377,1,1,2869,16,19,19,320,22,2,16,961,4,1028,2048,176,16,256,128,256,945,1024,2048,1078,2050,2,1034,2048,2072,16,16,978,1024,2048,3092,1032,1026,1024,3223,256,1032,1024,404,136,130,128,132,256,260,195,256,132,256,256,341,1,24,24,156,256,256,4,4,16,134,256,138,256,256,2,7315,289,34,34,188,260,4,260,4,785,256,256,1,228,256,1032,256,2048,21,32,32,4,128,256,7,1,2,27,9,1,29,8,32,32,32,24,40,8,63,448,64,128,1536,512,2048,455,88,128,104,128,128,8,728,97,2,1,360,1,2,65,2,1696,64,2048,1032,2048,3304,1088,64,4168,1024,1024,840,1024,8,3080,1024,1040,760,65,2,66,1857,770,1922,1,1,2048,2048,2177,2,2,64,2048,1304,1,2,2337,2,2050,1064,2048,2056,8,1048,2048,1064,2048,2048,8,1537,2,2563,516,514,2,518,2048,2048,2,455,8,16,728,265,2,1,360,1,2,9,2,1808,8,2048,1088,2048,3416,1032,8,4168,1024,1024,616,1024,64,3136,1024,1152,729,2,803,96,8,100,8,4,1025,2048,1024,2048,1385,802,16,16,1699,8,436,8,8,2048,106,2048,2049,2048,2993,2,98,98,168,1,1,440,2056,2056,2048,2048,1385,2,1170,8,8,2048,2048,3505,2,82,82,224,1,1,2126,161,2593,8,624,1,1,1,1554,2,880,2144,2328,2048,1400,8,1160,2048,2048,2984,8,9,104,16,1704,2048,2048,8,1024,2048,1611,16,1948,69,128,68,1,2048,128,544,2048,2048,2560,512,2644,1,2593,2,10,514,512,2969,128,224,752,1,2156,12,544,1264,1,329,2449,1,1316,1,64,272,3232,16,16,128,2701,16,2834,1,1,512,512,2838,1,609,4,1,756,1,17,2,1168,754,392,1,1484,2,1457,4,16,16,16,1308,4,4,16,3404,2132,1926,137,128,68,1717,2560,512,2690,512,130,513,818,2048,2048,2050,2049,16,178,2048,156,2048,16,16,136,2048,1,1,1017,1216,64,1344,2048,2048,2048,1606,2,1410,128,128,2048,2048,2690,132,132,1,1152,2048,2048,128,1530,2240,64,2368,2114,130,2176,128,2140,128,2088,8,2074,12,2088,8,8,16,1550,2064,16,1040,2048,530,2,2,8,16,1539,2049,1,516,2048,1,1,512,455,1536,512,2048,984,9,2,10,1577,546,1586,1,1,2048,2048,2065,2,2,8,2048,1248,1,2,2337,2,2050,1344,2048,2112,64,1216,2048,1344,2048,2048,64,1611,128,1780,13,16,12,1,2048,16,768,2048,2048,2560,512,2700,1,2817,2,66,514,512,2801,16,280,920,1,2380,68,768,1432,1,105,2225,1,1316,1,8,160,3344,128,128,16,2645,128,2722,1,1,512,512,2726,1,777,4,1,924,1,9,2,1168,922,112,1,1148,2,1457,4,128,128,128,1252,4,4,128,3180,2188,1590,81,16,12,1941,2560,512,2578,512,18,513,930,2048,2048,2050,2049,128,402,2048,169,2048,128,128,80,2048,1,1,729,1024,2048,3166,514,1024,1024,1281,128,2,1249,8,8,1,64,104,1400,1542,2,8,2048,2048,2910,2,2,803,8,1,867,8,8,8,1,776,8,8,2986,18,2148,10,756,2,1,1,2,1549,8,12,1162,2048,2060,2050,2,10,2,874,1024,2048,1036,2052,2056,2048,1456,2066,2724,8,2,1,1,1569,2048,2048,2081,1196,2048,2345,2,2458,1108,163,2,1108,2048,2052,5,1,2116,1260,2048,2456,8,2337,4,1,289,2048,12,1400,2058,12,12,1162,2048,2060,2050,2,1606,2048,6216,2048,2048,6210,2048,2048,10,2,10,2,1166,2064,10,16,2,1,546,1024,2048,68,10,729,1248,2048,2112,64,64,3166,2,3235,2,1,1024,1024,1377,264,160,1,2,2,1432,1,328,8,8,264,1024,1024,1638,2058,12,12,1162,2048,2060,2050,2,1368,2048,6210,2048,2048,6216,2048,2048,10,2,10,2,1166,2,2049,10,1,1,7371,64,76,2,9,1,1236,64,2,4,2048,3084,1024,1024,1024,2048,264,2,2,216,1600,2048,640,2048,512,801,1024,2048,1,2,11,1,13,455,1537,2,2563,516,514,2,518,2048,2048,2,1017,1048,8,1064,2048,2048,2048,1550,2,1074,16,16,2048,2048,2578,20,20,1,1040,2048,2048,16,1530,2072,8,2088,2058,18,2064,16,2252,16,2368,64,2242,68,2368,64,64,128,1606,2176,128,1152,2048,642,2,2,64,128,729,1304,2048,2056,8,8,3278,2,3347,2,1,1024,1024,1321,96,24,1,2,2,1264,1,104,64,64,96,1024,1024,1806,2114,68,68,1106,2048,2116,2050,2,1256,2048,6154,2048,2048,6216,2048,2048,66,2,66,2,1110,2,2049,19,1,1,7259,8,76,2,10,1,1180,8,2,4,2048,3140,1024,1024,1024,2048,96,2,2,216,1536,2048,512,1760,2056,8,520,8,2112,64,576,64,360,1536,2048,512,1616,2048,512,2048,512,1715,2048,512,1,81,2,2,1,2,225,64,66,2,8,10,2,1,2,72,16,80,128,128,128,967,1025,2048,1026,2048,2048,2,473,1544,2048,2056,1,224,1024,2048,258,64,66,128,130,216,264,8,96,256,8,8,64,127,7,24,32,8,1,2,911,176,16,208,256,256,256,433,130,4,132,195,20,4,156,4,4,146,4,1,720,130,4,278,1,2,1025,2048,1024,2048,1025,2048,16,3079,1040,32,1056,1049,34,2,1058,1,19,2,3113,2,16,1,1,497,130,2,130,1,4123,32,34,16,32,131,1,133,256,256,256,1027,1028,1,1,2048,2053,6,6,2,2048,911,128,256,433,18,4,20,531,132,4,156,4,4,146,4,1,720,18,4,166,1,2,1025,2048,1024,2048,1025,2048,128,1457,2,4,1047,128,166,2,2,723,32,34,9,2,230,2,2,32,1746,468,1,833,201,869,20,201,1,212,1,1,1,2065,2048,6293,2048,2208,2208,448,8,1,2204,16,16,4,4,2048,1746,4,164,20,24,1,6294,2048,2240,2240,336,8,1,2524,1,321,4,1,1,180,8,548,4,2338,32,32,2494,192,16,193,1,16,1026,4,2,4,2048,1459,128,1724,5,1,260,1,1,304,1,2048,16,1104,2048,1221,16,150,4,4,472,9,1068,1,2048,2197,16,2070,2048,2741,6,841,5,476,8,336,16,2185,1,130,261,4,2048,2517,128,2202,1,1,16,16,2217,1,202,1,1,2579,1,6,1,801,1557,578,4,2601,1,2627,4,128,128,128,154,1,1,128,1556,612,529,1,8,192,528,2643,5,1,2085,7,5,1,2452,128,545,529,1,1,464,128,128,561,1,128,528,2048,2048,1,2033,128,256,1158,2,138,256,256,2433,2304,256,3058,128,256,2180,260,264,256,3223,32,260,256,2100,24,18,16,20,32,36,1078,2048,2104,2,2,16,16,2067,1,20,20,24,2,2,16,22,32,26,32,32,2,1027,2049,1,1028,2048,2048,1,4,903,441,26,8,12,62,8,16,1024,2048,2,1216,1,2176,2048,1433,520,2,2,1546,128,398,128,128,1588,128,2,2,2,2048,626,32,2048,32,2048,2048,1770,296,1,1318,12,44,4,282,2048,1556,176,2572,4,4,2180,2080,32,2276,32,2098,146,12,2048,2785,34,2,2338,5,3,2,2202,8,288,160,32,32,1376,32,32,2824,8,8,2208,192,192,1,1465,8,16,1230,18,2,1,306,16,16,1552,8,1,2048,2048,2176,728,353,8,8,2048,2,1358,2,146,2,1586,1,2048,2048,2048,2313,8,2,2048,2048,2858,130,1549,13,1905,1,1,2,1,308,2,12,2210,2,10,2060,8,2050,2,2746,8,16,156,10,168,8,796,2092,140,456,9,6,1,1640,2,4,458,1554,880,16,20,1,12,1748,1,227,864,1555,1,16,1740,336,8,464,2,1,593,1,16,132,728,2058,12,12,2210,2,10,2060,8,865,2050,2,2050,2,194,8,8,2240,8,8,8,1370,2048,12,2049,1,1,193,130,2304,8,16,1433,224,32,2048,2048,2718,2,736,32,32,2563,2,2209,8,8,1,193,578,2344,17,9,8,40,8,2729,144,1742,162,2504,264,8,880,1184,8,456,32,4305,256,2,2,2,3138,16,16,2,2355,300,5104,1,12,1,300,4,2,2,2258,128,128,8,8,2,1578,2048,2092,8,8,2475,128,712,1,609,128,128,2060,12,1748,2048,2576,2590,4,182,5,12,172,8,12,5,1,128,1506,1664,2048,480,128,2048,32,10,32,32,40,8,2,440,1152,2048,2176,1224,2064,16,1304,2048,2048,2056,1552,2048,2048,8,8,601,1024,2048,1640,2048,2056,10,1,10,2,11,1,13,16,16,16,24,32,8,911,1027,1028,1,1,2048,2053,6,6,2,2048,2033,16,32,1046,2,26,32,32,2097,2080,32,3058,16,32,2068,36,40,32,3223,256,36,32,2436,136,130,128,132,256,260,1414,2048,2440,2,2,128,128,2179,1,132,132,136,2,2,128,134,256,138,256,256,2,1457,528,2048,2048,2641,128,464,48,128,128,2450,4,1,1,128,2082,4,4,2,4,1558,2178,132,132,2200,128,26,2306,2,1577,2176,128,2176,128,656,2,2,2576,2,2,2,742,2048,258,2049,1,1,1731,2048,2307,1,1,4,4,1860,2048,2048,4,6,528,692,16,16,156,2,528,4,4,450,128,132,4,4,7327,3,1,4,227,33,1,36,4,257,1,260,4,432,1024,2048,3392,1024,1024,1059,1,4,2048,323,1,4,1,4,3,1,4,3296,256,1280,256,32,1056,32,1024,2048,144,32,160,256,256,256,903,1025,2048,1026,2048,2048,2,1464,2072,8,2088,536,8,2080,1,2,193,1,130,2,152,264,8,160,256,256,8,32,63,7,8,16,1,2,455,88,8,104,128,128,128,216,65,2,66,99,8,139,1,1,173,1,1,808,1,2,9,2,1032,2048,1024,2048,1536,512,2048,985,96,128,2,490,64,128,67,128,1572,1,2048,1032,2048,3113,1026,2,4106,1024,1024,522,1024,8,3080,1024,1040,1539,513,1,1541,512,2048,2048,2048,455,64,128,216,9,2,10,97,2,170,2,78,2,2,8,864,1,2,65,2,1088,2048,1024,2048,1536,512,2048,3659,512,1024,596,13,1100,1,1,4,80,652,4,1024,1152,128,732,217,8,8,881,4,226,1,1,1024,169,1024,1025,1024,1384,1,97,97,680,128,4,824,1040,1152,1024,1024,3733,512,1024,530,1026,1040,1024,216,8,12,672,1024,1024,512,1024,216,108,14,108,512,1024,76,8,8,216,8,300,1,1,161,1,729,64,614,10,1,14,2,1,1088,2048,1024,2048,1258,610,1,1,1622,2,180,2,1,2048,330,2048,2049,2048,2804,64,76,76,274,2,2,304,2049,2050,2048,2048,1258,64,1108,2,2,2048,2048,3316,64,76,76,280,1,1,2315,18,2566,2,780,2,1,2,1601,64,812,2072,2337,2048,1320,2,1042,2048,2048,2864,2,2,514,10,1554,2048,2048,1,1024,2048,1547,17,1,2577,1057,16,1558,2,512,1,512,548,1,2636,16,592,16,2993,136,20,80,16,1160,1,1,1,3588,512,528,8,72,128,1,64,128,1536,2560,512,455,1,2,761,264,16,2,378,8,16,11,16,1796,1,2048,1088,2048,3393,1026,2,4162,1024,1024,578,1024,64,3136,1024,1152,729,8,782,66,1,70,2,1,1032,2048,1024,2048,1370,778,1,1,1678,2,404,2,1,2048,106,2048,2049,2048,2972,8,76,76,162,2,2,416,2049,2050,2048,2048,1370,8,1164,2,2,2048,2048,3484,8,76,76,224,1,1,2147,130,2566,2,612,2,1,2,1545,8,868,2144,2337,2048,1376,2,1154,2048,2048,2976,2,2,514,66,1666,2048,2048,1,1024,2048,1611,1,1969,80,128,113,16,2048,128,516,2048,2048,2560,512,2673,16,2578,512,512,988,128,168,2187,1,673,1,8,97,2701,514,2314,6,1240,8,88,16,2698,512,516,6,1,128,2707,1,2849,16,16,512,512,2853,1,598,1,16,756,2,17,1,1177,748,392,4,1520,8,1436,4,1,1,1,1313,4,4,1,3443,2117,1956,136,128,100,1684,2560,512,2720,528,164,512,812,2048,2048,2052,2052,1,168,2048,1,2060,1,1,176,2048,16,16,984,1216,64,1344,2048,2048,2048,1632,8,1416,128,128,2048,2048,2728,144,144,8,1152,2048,2048,128,1512,2240,64,2368,2120,136,2176,128,2161,128,2050,2,2057,10,2050,2,1,2,1569,2048,1026,2048,2048,554,10,2,1,2,1544,2064,16,560,2048,16,16,512,455,1539,513,1,1541,512,2048,2048,2048,1603,129,1,2689,1281,128,1670,2,512,1,512,772,1,2636,128,648,128,2993,80,132,136,128,1104,1,1,1,3588,512,640,64,72,16,1,8,16,760,1048,8,1064,2048,2048,2048,1800,64,1136,16,16,2048,2048,2896,96,96,8,1040,2048,2048,16,1400,2072,8,2088,2120,80,2064,16,2441,16,2050,2,2113,66,2050,2,1,2,1793,2048,1026,2048,2048,834,66,2,1,2,1752,2120,80,80,1832,2048,2320,64,64,576,64,576,64,736,64,832,2048,265,1,2,8,512,8,16,448,1536,2560,512,1600,2176,128,896,2048,128,128,512,64,128,63,7,8,16,11,16,13,16,16,1,1,2,455,64,128,217,74,12,12,94,8,8,98,8,8,2,296,10,96,1536,512,2048,7691,1536,512,2048,1548,513,1,2049,1,528,16,2064,16,473,64,128,82,128,128,1733,512,2048,64,1554,512,2048,512,2048,1536,512,2048,76,16,144,16,1,129,1,64,128,1547,529,18,18,1556,512,524,1,1,2049,1,2049,1,2252,16,80,4,267,1,512,1,2048,1536,512,2048,967,193,2,323,68,66,2,70,256,256,2,505,72,128,80,128,128,16,206,2,242,16,16,64,64,338,20,20,1,80,16,8,16,634,8,16,138,144,18,16,1227,2048,144,16,1154,2176,2050,2048,3200,1024,1280,1222,64,1344,2048,2048,2306,2050,2,1024,2048,1241,72,1,8,1134,2,97,2,2,1462,2,1,1,1,2048,904,256,2048,256,2048,2048,1898,352,2,1317,12,114,16,232,2048,1206,416,2128,1,1,2060,2304,256,2222,13,86,2305,256,2048,2842,264,8,2316,8,10,10,2283,64,288,288,256,256,1797,256,289,64,64,64,2338,260,260,2,2008,192,64,256,1248,72,8,264,8,2112,64,2304,256,3048,192,64,256,2256,64,256,64,256,243,64,256,1,2065,2,2,1,2,1057,2048,2050,2,8,10,2,1,2,1048,2048,1064,2048,2048,8,967,195,257,1,68,256,1,1,64,1273,1287,64,66,1,264,16,2048,8,16,1358,2,386,2,2417,528,66,66,2,912,2048,2048,2048,2371,2561,2,2244,64,2,64,1,1284,64,2050,2,1528,72,128,80,128,128,16,1624,8,104,128,128,2248,144,144,16,2144,128,128,8,8,2048,2680,8,16,2184,144,88,16,3273,2,144,16,2177,130,67,2,131,1,133,1601,2048,2115,2,66,128,130,2,1,2,1240,2120,80,80,1800,2304,256,2304,256,6216,2048,2048,64,1315,2048,545,2048,100,4,8,8,256,8,16,448,1536,512,2048,1600,128,2752,768,640,128,896,2048,2048,128,1728,2112,64,768,2048,64,64,512,127,15,3,4,1,19,20,1,1,32,37,6,6,2,32,19,33,1,20,32,32,1,4,903,129,2,130,256,256,256,441,152,8,168,158,10,2,162,8,8,201,2,32,698,8,16,12,16,1476,2,2048,1025,2048,1030,2048,2,3087,1027,1,1029,1073,16,1046,2,2,16,2098,16,16,1,1,2114,440,144,16,192,16,4115,1,21,1,2,144,32,160,256,256,256,1048,1056,8,8,2048,2088,48,48,16,2048,903,129,256,130,256,256,2,3207,1027,1,1029,1283,1,1537,1,1796,1,1,128,440,8,16,328,16,193,2,1,2,24,8,32,1464,152,8,168,6296,2056,8,2208,8,8,1224,2048,32,2617,8,16,520,16,5123,4,128,192,2,577,2048,2,1048,2056,8,1056,2048,2048,8,32,896,1152,256,1280,2048,2048,2048,1152,2048,1280,2048,2048,256,127,7,1,2,27,9,1,29,8,32,32,32,24,40,8,903,131,1,133,256,256,256,441,152,8,168,449,128,1024,2048,8,16,1602,2,2050,2048,3096,1032,8,1120,32,32,8,32,896,128,256,1408,128,1664,2048,2048,2048,1024,2048,63,7,1,2,8,16,448,64,128,1536,512,2048};

const int MAXN = 50050, magicLen = 4526;
#define size(v) (int(v.size()))
#define pc(x) __builtin_popcount(x)

int ch[MAXN][15], top, val[MAXN], cc;

void build(int x, vector <int> &v) {
    if (size(v) == 1) { val[x] = v[0]; return; }
    const int id = magic[x];
    vector <int> buc[len + 1];
    for (auto i: v) buc[pc(i & id)].push_back(i);
    for (int i = 0; i <= len; i++) {
        if (size(buc[i]) >= 2) build(ch[x][i] = ++top, buc[i]);
        else if (size(buc[i])) ++cc, build(ch[x][i] = magicLen + cc, buc[i]);
    }
}

int all, n, pre[MAXN];
int get() { int res = read(); if (res == n) exit(0); return res; }
int init_ask(int r) {
    const int l = r - len + 1;
    for (int i = 1; i <= n; i++)
        putchar((i >= l && i <= r) ? 'F' : 'T');
    putchar('\n'); fflush(stdout); return get();
}
int ask(int r, int st) {
    if (st == (1 << len) - 1) return all - pre[r];
    const int l = r - len + 1;
    for (int i = 1; i <= n; i++)
        putchar((i >= l && i <= r) ? ("FT"[(st >> (i - l)) & 1]) : 'T');
    putchar('\n'); fflush(stdout);
    return (pc(st) + (all - pre[r]) - len + (get() - pre[r])) >> 1;
}
bool final_ask(int x) {
    for (int i = 1; i <= n; i++) putchar(i == x ? 'F' : 'T');
    putchar('\n'); fflush(stdout); return get() - all == -1;
}

int solve(int x, int r) {
    if (val[x] != -1) return val[x];
    const int id = magic[x], res = ask(r, id);
    return solve(ch[x][res], r);
}

bool ans[MAXN];

int main() {
    n = read(); int i, j;

    for (i = 1; i < MAXN; i++) val[i] = -1;
    vector <int> v;
    for (i = 0; i < (1 << len); i++) v.push_back(i);
    build(top = 1, v);
    
    for (i = 1; i <= n; i++) putchar('T'); putchar('\n'); fflush(stdout);
    all = get();

    for (i = len; i <= n; i += len)
        pre[i] = all - ((all - init_ask(i) + len) >> 1);
    
    for (i = len; i <= n; i += len) {
        int res = solve(1, i);
        for (int j = 0; j < len; j++) ans[i - len + 1 + j] = (res >> j) & 1;
    }
    for (i = i - len + 1; i <= n; i++) ans[i] = final_ask(i);
    for (i = 1; i <= n; i++) putchar("FT"[ans[i]]);
    putchar('\n');
    return 0;
}