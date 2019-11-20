#ifndef __MATHS_H__
#define __MATHS_H__

#ifdef __AVR__
#include <Arduino.h>
#else
#define min(a, b) ((a) < (b) ? (a) : (b))   // a < b ? a : b
#define max(a, b) ((a) > (b) ? (a) : (b))   // a > b ? a : b
#endif

#define sgn(x) (((x) > 0) - ((x) < 0))  // (x > 0) - (x < 0)

#define _abs(x) ((x) < 0 ? -(x) : (x))  // x < 0 ? -x : x
#define absdiff(a, b) (_abs((a) - (b))) // _abs(a - b)

#define clamp(x, a, b) ((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))  // x < a ? a : (x > b ? b : x)
#define clamp01(x) ((x) < 0.0 ? 0.0 : ((x) > 1.0 ? 1.0 : (x)))      // x < 0.0 ? 0.0 : (x > 1.0 ? 1.0 : x)
#define clamp11(x) ((x) < -1.0 ? -1.0 : ((x) > 1.0 ? 1.0 : (x)))    // x < -1.0 ? -1.0 : (x > 1.0 ? 1.0 : x)

#define normalize01(x, min, max) (((x) - (min)) / ((max) - (min)))                          // (x - min) / (max - min)
#define normalize11(x, min, max) (((x) - (((min) + (max)) / 2)) / (((max) - (min)) / 2))    // (x - ((min + max) / 2)) / ((max - min) / 2)
#define denormalize01(x, min, max) (((x) * ((max) - (min))) + (min))                        // (x * ((max) - min)) + (min)
#define denormalize11(x, min, max) (denormalize01(((x) + 1) / 2, (min), (max)))             // denormalize01((x + 1) / 2, min, max)

#endif // __MATHS_H__
