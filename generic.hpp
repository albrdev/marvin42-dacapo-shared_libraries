#ifndef __GENERIC_HPP__
#define __GENERIC_HPP__

#include <stdint.h> /* uint8_t, uint16_t */
#include <stdlib.h> /* size_t */
#ifdef __AVR__
#include <SoftwareSerial.h>
#else
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#define clamp(x, a, b) ((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))  // x < a ? a : (x > b ? b : x)
#define clamp01(x) ((x) < 0.0 ? 0.0 : ((x) > 1.0 ? 1.0 : (x)))      // x < 0.0 ? 0.0 : (x > 1.0 ? 1.0 : x)
#define clamp11(x) ((x) < -1.0 ? -1.0 : ((x) > 1.0 ? 1.0 : (x)))    // x < -1.0 ? -1.0 : (x > 1.0 ? 1.0 : x)

#define normalize01(x, min, max) (((x) - (min)) / ((max) - (min)))                          // (x - min) / (max - min)
#define normalize11(x, min, max) (((x) - (((min) + (max)) / 2)) / (((max) - (min)) / 2))    // (x - ((min + max) / 2)) / ((max - min) / 2)
#define denormalize01(x, min, max) (((x) * ((max) - (min))) + (min))                        // (x * ((max) - min)) + (min)
#define denormalize11(x, min, max) (((x) + (((min) + (max)) / 2)) * (((max) - (min)) / 2))  // (x + ((min + max) / 2)) * ((max - min) / 2)

#ifdef __AVR__
int spprintf(const char* const fmt, ...);
int spprintf(SoftwareSerial& serialPort, const char* const fmt, ...);
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    const char* hexstr(const void* const data, const size_t size);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __GENERIC_HPP__
