#ifndef __GENERIC_HPP__
#define __GENERIC_HPP__

#include <stdlib.h> /* size_t */
#include <stdio.h>
#include <stdint.h> /* uint8_t, uint16_t */
#include "maths.h"

#ifdef __AVR__
#include <Arduino.h>
#include <SoftwareSerial.h>
#endif

#define NOP ((void)0)

#if defined(__AVR__) || defined(ESP8266)
    #define ANALOG_MAX          ((1 << 10) - 1)

    #ifdef M42_DEBUG
    #define PrintDebug(x)       Serial.print(x)
    #define PrintDebugLine(x)   Serial.println(x)
    #else
    #define PrintDebug(x)       NOP
    #define PrintDebugLine(x)   NOP
    #endif
#else
    #ifdef M42_DEBUG
    #define PrintfDebug(...)    fprintf(stderr, __VA_ARGS__)
    #define PrintfDebug2(...)   printf(__VA_ARGS__); fflush(stdout)
    #else
    #define PrintfDebug(...)    NOP
    #define PrintfDebug2(...)   NOP
    #endif
#endif

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
