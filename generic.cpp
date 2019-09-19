#include "generic.hpp"
#include <stdint.h>     /* uint8_t */
#include <stdarg.h>     /* vsnprintf() */
#ifdef __AVR__
#include <Arduino.h>    /* Serial, min() */
#endif

#ifdef __AVR__
static char _format_buf[256 + 1];
int spprintf(const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(_format_buf, sizeof(_format_buf), fmt, args);
    va_end(args);

    Serial.print(_format_buf);
    return len;
}

int spprintf(SoftwareSerial& serialPort, const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(_format_buf, sizeof(_format_buf), fmt, args);
    va_end(args);

    serialPort.print(_format_buf);
    return len;
}
#endif

#define HEXSTRBUF_SIZE 128
char const _hexchar_map[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
static char _hexstr_buf[HEXSTRBUF_SIZE + 1];
const char* hexstr(const void* const data, const size_t size)
{
    const uint8_t* ptr = (const unsigned char*)data;
    size_t max = min(size, HEXSTRBUF_SIZE / 2);
    size_t j = 0U;
    for(size_t i = 0U; i < max; i++)
    {
        _hexstr_buf[j] = _hexchar_map[(ptr[i] & 0xF0) >> 4];
        j++;
        _hexstr_buf[j] = _hexchar_map[(ptr[i] & 0x0F)];
        j++;
    }

    _hexstr_buf[j] = '\0';
    return _hexstr_buf;
}
