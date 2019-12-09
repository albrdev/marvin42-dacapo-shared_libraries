#ifndef __CUSTOM_PACKETS_H__
#define __CUSTOM_PACKETS_H__

#include <stdint.h> /* uint32_t */
#include <string.h> /* size_t, memcpy() */
#include "packet.h"

typedef struct _packet_motorbalance packet_motorbalance_t;
typedef struct _packet_direction packet_direction_t;
typedef struct _packet_motorpower packet_motorpower_t;
typedef struct _packet_motorrun packet_motorrun_t;

typedef struct _packet_orientationdata packet_orientationdata_t;
typedef struct _packet_proximitydata packet_proximitydata_t;

enum CustomPacketType
{
    CPT_MOTORSTOP = PT_MAX,
    CPT_MOTORBALANCE,
    CPT_DIRECTION,
    CPT_MOTORPOWER,
    CPT_MOTORRUN,
    CPT_ORIENTATIONDATA,
    CPT_PROXIMITYDATA
};

struct __attribute__((packed)) _packet_motorbalance
{
    packet_header_t header;

    single_t left;
    single_t right;
};

struct __attribute__((packed)) _packet_direction
{
    packet_header_t header;

    vector2data_t direction;
};

struct __attribute__((packed)) _packet_motorpower
{
    packet_header_t header;

    single_t power;
};

struct __attribute__((packed)) _packet_motorrun
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

void packet_mkmotorbalance(struct _packet_motorbalance* const pkt, const single_t left, const single_t right);
void packet_mkdirection(struct _packet_direction* const pkt, const vector2data_t* const direction);
void packet_mkmotorpower(struct _packet_motorpower* const pkt, const single_t power);
void packet_mkmotorrun(struct _packet_motorrun* const pkt, const vector2data_t* const direction, const single_t power);

void packet_mkorientationdata(struct _packet_orientationdata* const pkt, const single_t velocity, const single_t w, const single_t x, const single_t y, const single_t z);
void packet_mkproximitydata(struct _packet_proximitydata* const pkt, const single_t distance, const single_t angle);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __CUSTOM_PACKETS_H__ */
