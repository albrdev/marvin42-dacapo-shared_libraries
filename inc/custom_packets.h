#ifndef __CUSTOM_PACKETS_H__
#define __CUSTOM_PACKETS_H__

#include <stdint.h> /* uint32_t */
#include <string.h> /* size_t, memcpy() */
#include "packet.h"

typedef struct _packet_motorrun packet_motorrun_t;
typedef struct _packet_motorrun2 packet_motorrun2_t;

typedef struct _packet_orientationdata packet_orientationdata_t;
typedef struct _packet_proximitydata packet_proximitydata_t;

enum CustomPacketType
{
    CPT_STATUS = PT_MAX,
    CPT_MOTORSTOP,
    CPT_MOTORRUN,
    CPT_MOTORRUN2,
    CPT_ORIENTATIONDATA,
    CPT_PROXIMITYDATA
};

struct __attribute__((packed)) _packet_motorrun
{
    packet_header_t header;

    single_t left;
    single_t right;
};

struct __attribute__((packed)) _packet_motorrun2
{
    packet_header_t header;

    vector2data_t direction;
    single_t power;
};

struct __attribute__((packed)) _packet_orientationdata
{
    packet_header_t header;

    single_t velocity;
    quaterniondata_t rotation;
};

struct __attribute__((packed)) _packet_proximitydata
{
    packet_header_t header;

    single_t distance;
    single_t angle;
};

#ifdef __cplusplus
extern "C"
{
#endif

void packet_mkmotorrun(struct _packet_motorrun *const pkt, const single_t left, const single_t right);
void packet_mkmotorrun2(struct _packet_motorrun2* const pkt, const vector2data_t direction, const single_t power);

void packet_mkorientationdata(struct _packet_orientationdata* const pkt, const single_t velocity, const single_t w, const single_t x, const single_t y, const single_t z);
void packet_mkproximitydata(struct _packet_proximitydata* const pkt, const single_t distance, const single_t angle);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __CUSTOM_PACKETS_H__ */
