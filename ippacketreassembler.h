#ifndef IPPACKETREASSEMBLER_H
#define IPPACKETREASSEMBLER_H

#include "headers.h"
#include "Models/ippacket.h"

namespace HttpSniffer
{

class IpPacketReassembler
{
public:
    IpPacketReassembler();

    IpPacket reassemble(const IpPacket& ip_packet);

private:
    unordered_map<uint32_t, vector<IpPacket> > _fragmented_packets;
};

}

#endif // IPPACKETREASSEMBLER_H
