#ifndef IP_PACKET_REASSEMBLER_TEST_H
#define IP_PACKET_REASSEMBLER_TEST_H

#include <gtest/gtest.h>

#include "../headers.h"
#include "../Models/ippacket.h"
#include "../ippacketreassembler.h"

using namespace HttpSniffer;

TEST(test1, test1)
{
    IpPacket ip_packet;
    IpPacketReassembler ip_reassembler;
}

#endif // IP_PACKET_REASSEMBLER_TEST_H
