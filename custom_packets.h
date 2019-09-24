#ifndef __CUSTOM_PACKETS_H__
#define __CUSTOM_PACKETS_H__

#include <stdint.h> /* uint32_t */
#include <string.h> /* size_t, memcpy() */
#include "packet.h"

typedef struct _packet_motorrun packet_motorrun_t;
typedef struct _packet_motorjsdata packet_motorjsdata_t;

enum CustomPacketType
{
    CPT_STATUS = PT_MAX,
    CPT_MOTORRUN,
    CPT_MOTORSTOP,
    CPT_MOTORJSDATA
};

struct __attribute__((packed)) _packet_motorrun
{
    packet_header_t header;

    uint32_t left;
    uint32_t right;
};

struct __attribute__((packed)) _packet_motorjsdata
{
    packet_header_t header;

    uint32_t balance;
    int8_t direction;
};

#ifdef __cplusplus
extern "C"
{
#endif
    void packet_mkmotorrun(struct _packet_motorrun *const pkt, const float left, const float right);
    void packet_mkmotorjsdata(struct _packet_motorjsdata* const pkt, const float balance, const int8_t direction);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __CUSTOM_PACKETS_H__ */
