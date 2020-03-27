#ifndef __GENERIC_HPP__
#define __GENERIC_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "maths.h"

#ifdef __AVR__
#include <Arduino.h>
#include <Stream.h>
#endif

#ifndef NOP
#define NOP ((void)0)
#endif

#if defined(__AVR__) || defined(ESP8266)
    #define ANALOG_MAX          ((1 << 10) - 1)
#endif

#ifdef __AVR__
#ifndef AVRPRINTF_BUFFERSIZE
#define AVRPRINTF_BUFFERSIZE 128
#endif
int spprintf(const char* const fmt, ...);
int spprintf(Stream& serialPort, const char* const fmt, ...);
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    #ifndef HEXSTR_BUFFERSIZE
    #define HEXSTR_BUFFERSIZE 128
    #endif
    const char* hexstr(const void* const data, const size_t size);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __GENERIC_HPP__
