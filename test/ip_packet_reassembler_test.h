#ifndef IP_PACKET_REASSEMBLER_TEST_H
#define IP_PACKET_REASSEMBLER_TEST_H

#include <gtest/gtest.h>

#include "../headers.h"
#include "../Models/ippacket.h"
#include "../ippacketreassembler.h"
#include "../Exceptions/ippacketreassemblerexcetions.h"

namespace HttpSniffer
{

void PrintTo(const IpPacket& ip, ::std::ostream* os)
{
    // header
    *os << "header={";
    *os << "version=" << static_cast<uint32_t>(ip.header.version) << ",";
    *os << "ihl=" << static_cast<uint32_t>(ip.header.ihl) << ",";
    *os << "dscp=" << static_cast<uint32_t>(ip.header.dscp) << ",";
    *os << "ecn=" << static_cast<uint32_t>(ip.header.ecn) << ",";
    *os << "total_length=" << static_cast<uint32_t>(ip.header.total_length) << ",";
    *os << "id=" << static_cast<uint32_t>(ip.header.id) << ",";
    *os << "dont_fragment=" << static_cast<uint32_t>(ip.header.dont_fragment) << ",";
    *os << "more_fragments=" << static_cast<uint32_t>(ip.header.more_fragments) << ",";
    *os << "fragment_offset=" << static_cast<uint32_t>(ip.header.fragment_offset) << ",";
    *os << "ttl=" << static_cast<uint32_t>(ip.header.ttl) << ",";
    *os << "protocol=" << static_cast<uint32_t>(ip.header.protocol) << ",";
    *os << "crc=" << static_cast<uint32_t>(ip.header.crc) << ",";
    *os << "src_addr=" << static_cast<uint32_t>(ip.header.src_addr) << ",";
    *os << "dst_addr=" << static_cast<uint32_t>(ip.header.dst_addr) << ",";
    *os << "options=[";
    IpPacket& _ip = const_cast<IpPacket&>(ip);
    for (vector<uint8_t>::iterator it = _ip.header.options.begin();
         it != _ip.header.options.end(); ++it)
    {
        *os << static_cast<uint32_t>(*it);
        if (it != _ip.header.options.end()-1)
            *os << ",";
    }
    *os << "]}, data=[";
    for (vector<uint8_t>::iterator it = _ip.data.begin();
         it != _ip.data.end(); ++it)
    {
        *os << static_cast<uint32_t>(*it);
        if (it != _ip.data.end()-1)
            *os << ",";
    }
    *os << "]";
}

}  // namespace foo

using namespace HttpSniffer;

class IpPacketReassemblerTest : public testing::Test
{
protected:
    virtual void SetUp()
    {
//        ip_packet.data.push_back(1);
//        ip_packet.data.push_back(3);
//        ip_packet.data.push_back(5);
//        ip_packet.data.push_back(7);
    }

    virtual void TearDown()
    {
    }

//    IpPacket ip_packet;
};


TEST_F(IpPacketReassemblerTest, simple_ip_packet)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);

    IpPacketReassembler ip_reassembler;

    IpPacket reassembled = ip_reassembler.reassemble(ip_packet);
    EXPECT_EQ(reassembled, ip_packet);

    ip_packet.header.id = 13;

    reassembled = ip_reassembler.reassemble(ip_packet);
    EXPECT_EQ(reassembled, ip_packet);
}

TEST_F(IpPacketReassemblerTest, simple_ip_packets)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);

    IpPacketReassembler ip_reassembler;

    IpPacket reassembled = ip_reassembler.reassemble(ip_packet);
    EXPECT_EQ(reassembled, ip_packet);

    ip_packet.header.id = 13;

    reassembled = ip_reassembler.reassemble(ip_packet);
    EXPECT_EQ(reassembled, ip_packet);
}

TEST_F(IpPacketReassemblerTest, without_fragments_ip_packet)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = false;
    ip_packet.header.fragment_offset = 0;

    IpPacketReassembler ip_reassembler;

    IpPacket reassembled = ip_reassembler.reassemble(ip_packet);
    EXPECT_EQ(reassembled, ip_packet);
}

//TEST_F(IpPacketReassemblerTest, broken_ip_packet)
//{
//    ip_packet.header.dont_fragment = false;
//    ip_packet.header.more_fragments = false;
//    ip_packet.header.fragment_offset = 10;

//    IpPacketReassembler ip_reassembler;
//    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), BrokenIpPacketException);
//}

TEST_F(IpPacketReassemblerTest, first_ip_packet)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = true;
    ip_packet.header.fragment_offset = 10;

    IpPacketReassembler ip_reassembler;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereAreNotAnotherIpPacketsException);
}

TEST_F(IpPacketReassemblerTest, there_is_ip_packet_with_zero_offset)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = true;
    ip_packet.header.fragment_offset = 10;

    IpPacketReassembler ip_reassembler;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereAreNotAnotherIpPacketsException);

    ip_packet.header.more_fragments = false;
    ip_packet.header.fragment_offset = 20;

//    try
//    {
//        ip_reassembler.reassemble(ip_packet);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << "\n";
//    }

    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereIsNotIpPacketWithZeroFragmentOffsetException);
}

TEST_F(IpPacketReassemblerTest, not_all_ip_packets_was_recived)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);
    ip_packet.data.push_back(11);
    ip_packet.data.push_back(13);
    ip_packet.data.push_back(17);
    ip_packet.data.push_back(29);

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = true;

    IpPacketReassembler ip_reassembler;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereAreNotAnotherIpPacketsException);

    ip_packet.header.more_fragments = false;
    ip_packet.header.fragment_offset = 2;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), NotAllIpPacketWereRecievedException);
}

TEST_F(IpPacketReassemblerTest, there_is_not_last_ip_packet)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);
    ip_packet.data.push_back(11);
    ip_packet.data.push_back(13);
    ip_packet.data.push_back(17);
    ip_packet.data.push_back(29);

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = true;

    IpPacketReassembler ip_reassembler;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereAreNotAnotherIpPacketsException);

    ip_packet.header.more_fragments = true;
    ip_packet.header.fragment_offset = 1;

//    try
//    {
//        ip_reassembler.reassemble(ip_packet);
//    }
//    catch (std::exception& e)
//    {
//        std::cout << e.what() << "\n";
//    }
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereIsNotLastIpPacketException);
}

TEST_F(IpPacketReassemblerTest, successful_reassembling)
{
    IpPacket ip_packet;
    ip_packet.data.push_back(1);
    ip_packet.data.push_back(3);
    ip_packet.data.push_back(5);
    ip_packet.data.push_back(7);
    ip_packet.data.push_back(11);
    ip_packet.data.push_back(13);
    ip_packet.data.push_back(17);
    ip_packet.data.push_back(29);

    IpPacket reassembled = ip_packet;

    ip_packet.header.dont_fragment = false;
    ip_packet.header.more_fragments = true;

    IpPacketReassembler ip_reassembler;
    EXPECT_THROW(ip_reassembler.reassemble(ip_packet), ThereAreNotAnotherIpPacketsException);

    ip_packet.header.more_fragments = false;
    ip_packet.header.fragment_offset = 1;
    ip_packet.data.clear();

    reassembled.data.push_back(31);
    ip_packet.data.push_back(31);

    reassembled.data.push_back(37);
    ip_packet.data.push_back(37);

    reassembled.header.total_length = ip_packet.header.size() + reassembled.data.size();
    EXPECT_EQ(reassembled, ip_reassembler.reassemble(ip_packet));
}

#endif // IP_PACKET_REASSEMBLER_TEST_H
