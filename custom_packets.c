#include "custom_packets.h"
#include "crc.h"

void packet_mkmotorrun(struct _packet_motorrun *const pkt, const float left, const float right)
{
    memcpy(&pkt->left, &left, sizeof(pkt->left));
    memcpy(&pkt->right, &right, sizeof(pkt->right));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORRUN);
}

void packet_mkmotorjsdata(struct _packet_motorjsdata* const pkt, const float balance, const int8_t direction)
{
    memcpy(&pkt->balance, &balance, sizeof(pkt->balance));
    memcpy(&pkt->direction, &direction, sizeof(pkt->direction));

    packet_mkheader(&pkt->header, sizeof(*pkt), CPT_MOTORJSDATA);
}
