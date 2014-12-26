#ifndef IPPACKETREASSEMBLER_H
#define IPPACKETREASSEMBLER_H

#include "headers.h"
#include "Models/ippacket.h"
#include "Containers/timing_map.hpp"

namespace HttpSniffer
{

class IpPacketReassembler
{
public:
    IpPacketReassembler();
    ~IpPacketReassembler();

    IpPacket reassemble(const IpPacket& ip_packet);

private:
    map<uint32_t, vector<IpPacket> > _fragmented_packets;
};

}

#endif // IPPACKETREASSEMBLER_H
