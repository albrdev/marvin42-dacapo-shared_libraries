#ifndef __PACKET_H__
#define __PACKET_H__

#include <string.h>
#include <stdint.h>

typedef struct _packet_header packet_header_t;

typedef float single_t;
typedef struct _vector2data vector2data_t;
typedef struct _vector3data vector3data_t;
typedef struct _quaterniondata quaterniondata_t;

enum PacketType
{
    PT_FALSE    = 0,
    PT_TRUE     = 1,
    PT_DEBUG    = 2,
    PT_MAX      = 3
};

struct __attribute__((packed)) _packet_header
{
    uint16_t chksum_header;
    uint16_t chksum_data;
    uint8_t type;
    uint16_t size;
};

struct __attribute__((packed)) _vector2data
{
    single_t x;
    single_t y;
};

struct __attribute__((packed)) _vector3data
{
    single_t x;
    single_t y;
    single_t z;
};

struct __attribute__((packed)) _quaterniondata
{
    single_t w;
    single_t x;
    single_t y;
    single_t z;
};

#define DEBUG_PAYLOAD_SIZE  128
struct __attribute__((packed)) _packet_debug
{
    packet_header_t header;

    uint8_t payload[DEBUG_PAYLOAD_SIZE];
};

#ifdef __cplusplus
extern "C"
{
#endif

int packet_verifyheader(const struct _packet_header *const pkt);
int packet_verifydata(const void *const pkt);

void packet_mkheader(struct _packet_header *const pkt, const size_t size, const uint8_t type);
void packet_mkbasic(void *const pkt, const uint8_t type);

void packet_mkdebug(struct _packet_debug* const pkt, const uint8_t* const payload, size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __PACKET_H__ */
