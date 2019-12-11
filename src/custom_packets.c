#include "custom_packets.h"
#include "crc.h"

void packet_mkmotorbalance(struct _packet_motorbalance* const pkt, const single_t left, const single_t right)
{
    memcpy(&pkt->left, &left, sizeof(pkt->left));
    memcpy(&pkt->right, &right, sizeof(pkt->right));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORBALANCE);
}

void packet_mkdirection(struct _packet_direction* const pkt, const vector2data_t* const direction)
{
    memcpy(&pkt->direction, direction, sizeof(pkt->direction));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_DIRECTION);
}

void packet_mkmotorpower(struct _packet_motorpower* const pkt, const single_t power)
{
    memcpy(&pkt->power, &power, sizeof(pkt->power));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORPOWER);
}

void packet_mkmotorrun(struct _packet_motorrun* const pkt, const vector2data_t* const direction, const single_t power)
{
    memcpy(&pkt->direction, direction, sizeof(pkt->direction));
    memcpy(&pkt->power, &power, sizeof(pkt->power));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORRUN);
}

void packet_mkmotorrotation(struct _packet_motorrotation* const pkt, const int8_t direction, const single_t power)
{
    memcpy(&pkt->direction, &direction, sizeof(pkt->direction));
    memcpy(&pkt->power, &power, sizeof(pkt->power));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORROTATION);
}

void packet_mkorientationdata(struct _packet_orientationdata* const pkt, const single_t velocity, const single_t w, const single_t x, const single_t y, const single_t z)
{
    memcpy(&pkt->velocity, &velocity, sizeof(pkt->velocity));
    memcpy(&pkt->rotation.w, &w, sizeof(pkt->rotation.w));
    memcpy(&pkt->rotation.x, &x, sizeof(pkt->rotation.x));
    memcpy(&pkt->rotation.y, &y, sizeof(pkt->rotation.y));
    memcpy(&pkt->rotation.z, &z, sizeof(pkt->rotation.z));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_ORIENTATIONDATA);
}

void packet_mkproximitydata(struct _packet_proximitydata* const pkt, const uint8_t id, const single_t distance, const single_t angle)
{
    memcpy(&pkt->id, &id, sizeof(pkt->id));
    memcpy(&pkt->distance, &distance, sizeof(pkt->distance));
    memcpy(&pkt->angle, &angle, sizeof(pkt->angle));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_PROXIMITYDATA);
}
