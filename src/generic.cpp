#include "generic.hpp"
#include <stdarg.h>

#ifdef __AVR__
static char _format_buf[AVRPRINTF_BUFFERSIZE + 1];

int avrprintf(Stream& stream, const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(_format_buf, sizeof(_format_buf), fmt, args);
    va_end(args);

    stream.print(_format_buf);
    return len;
}

int avrprintf(const char* const fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(_format_buf, sizeof(_format_buf), fmt, args);
    va_end(args);

    Serial.print(_format_buf);
    return len;
}
#endif

static char const _hexchar_map[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
static char _hexstr_buf[HEXSTR_BUFFERSIZE + 1];
const char* hexstr(const void* const data, const size_t size)
{
    const uint8_t* const ptr = (const uint8_t*)data;
    size_t max = min(size, HEXSTR_BUFFERSIZE / 2);
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
