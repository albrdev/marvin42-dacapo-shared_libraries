#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "maths.h"

#ifdef __AVR__
#include <Arduino.h>
#include <Stream.h>
#endif

#ifndef NOP
#define NOP             ((void)0)
#endif

#ifndef CONCAT
#define CONCAT(a, b)    a ## b
#endif

#if defined(__AVR__) || defined(ESP8266)
    #ifndef M42_DEBUGSOURCE
        #define M42_DEBUGSOURCE Serial
    #endif

    #define _DebugPrint(...)        M42_DEBUGSOURCE.print(__VA_ARGS__)
    #define _DebugPrintLine(...)    M42_DEBUGSOURCE.println(__VA_ARGS__)
    #define _DebugWrite(...)        M42_DEBUGSOURCE.write(__VA_ARGS__)
    #define _DebugFlush()           M42_DEBUGSOURCE.flush()
#else
    #define _DebugPrint(...)        fprintf(stderr, __VA_ARGS__)
    #define _DebugPrintLine(...)    do { fprintf(stderr, __VA_ARGS__); fputc('\n', stderr); } while(false)
    #define _DebugWrite(...)        fwrite(stderr, __VA_ARGS__)
    #define _DebugFlush()           fflush(stderr)
#endif

#if (DEBUG_MODE & 0b00000001) != 0
    #define _DebugPrint1(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine1(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite1(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush1()          _DebugFlush()
#else
    #define _DebugPrint1(...)       NOP
    #define _DebugPrintLine1(...)   NOP
    #define _DebugWrite1(...)       NOP
    #define _DebugFlush1()          NOP
#endif

#if (DEBUG_MODE & 0b00000010) != 0
    #define _DebugPrint2(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine2(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite2(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush2()          _DebugFlush()
#else
    #define _DebugPrint2(...)       NOP
    #define _DebugPrintLine2(...)   NOP
    #define _DebugWrite2(...)       NOP
    #define _DebugFlush2()          NOP
#endif

#if (DEBUG_MODE & 0b00000100) != 0
    #define _DebugPrint3(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine3(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite3(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush3()          _DebugFlush()
#else
    #define _DebugPrint3(...)       NOP
    #define _DebugPrintLine3(...)   NOP
    #define _DebugWrite3(...)       NOP
    #define _DebugFlush3()          NOP
#endif

#if (DEBUG_MODE & 0b00001000) != 0
    #define _DebugPrint4(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine4(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite4(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush4()          _DebugFlush()
#else
    #define _DebugPrint4(...)       NOP
    #define _DebugPrintLine4(...)   NOP
    #define _DebugWrite4(...)       NOP
    #define _DebugFlush4()          NOP
#endif

#if (DEBUG_MODE & 0b00010000) != 0
    #define _DebugPrint5(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine5(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite5(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush5()          _DebugFlush()
#else
    #define _DebugPrint5(...)       NOP
    #define _DebugPrintLine5(...)   NOP
    #define _DebugWrite5(...)       NOP
    #define _DebugFlush5()          NOP
#endif

#if (DEBUG_MODE & 0b00100000) != 0
    #define _DebugPrint6(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine6(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite6(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush6()          _DebugFlush()
#else
    #define _DebugPrint6(...)       NOP
    #define _DebugPrintLine6(...)   NOP
    #define _DebugWrite6(...)       NOP
    #define _DebugFlush6()          NOP
#endif

#if (DEBUG_MODE & 0b01000000) != 0
    #define _DebugPrint7(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine7(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite7(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush7()          _DebugFlush()
#else
    #define _DebugPrint7(...)       NOP
    #define _DebugPrintLine7(...)   NOP
    #define _DebugWrite7(...)       NOP
    #define _DebugFlush7()          NOP
#endif

#if (DEBUG_MODE & 0b10000000) != 0
    #define _DebugPrint8(...)       _DebugPrint(__VA_ARGS__)
    #define _DebugPrintLine8(...)   _DebugPrintLine(__VA_ARGS__)
    #define _DebugWrite8(...)       _DebugWrite(__VA_ARGS__)
    #define _DebugFlush8()          _DebugFlush()
#else
    #define _DebugPrint8(...)       NOP
    #define _DebugPrintLine8(...)   NOP
    #define _DebugWrite8(...)       NOP
    #define _DebugFlush8()          NOP
#endif

#ifdef DEBUG_MODE
    #define DebugPrint(...)     _DebugPrint(__VA_ARGS__)
    #define DebugPrintLine(...) _DebugPrintLine(__VA_ARGS__)
    #define DebugWrite(...)     _DebugWrite(__VA_ARGS__)
    #define DebugFlush()        _DebugFlush()
#else
    #define DebugPrint(...)     NOP
    #define DebugPrintLine(...) NOP
    #define DebugWrite(...)     NOP
    #define DebugFlush()        NOP
#endif

#define DebugPrintN(id, ...)        CONCAT(_DebugPrint, id)(__VA_ARGS__)
#define DebugPrintLineN(id, ...)    CONCAT(_DebugPrintLine, id)(__VA_ARGS__)
#define DebugWriteN(id, ...)        CONCAT(_DebugWrite, id)(__VA_ARGS__)
#define DebugFlushN(id)             CONCAT(_DebugFlush, id)()

#endif // __DEBUG_HPP__
