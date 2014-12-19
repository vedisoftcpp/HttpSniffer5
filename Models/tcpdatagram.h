#ifndef TCPDATAGRAM_H
#define TCPDATAGRAM_H

#include "../headers.h"
#include "ippacket.h"

namespace HttpSniffer
{

struct tcp_header_t
{
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_number;
    uint32_t ask_number;
    uint8_t stuff;
    uint8_t flags;
    uint16_t window;
    uint16_t checksum;
    uint16_t urg_ptr;
};

struct TcpDatagramHeader
{
    TcpDatagramHeader();
    TcpDatagramHeader(const tcp_header_t* th);

    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_number;
    uint32_t ask_number;
    uint8_t data_offset;
    bool ns_flag;
    bool cwr_flag;
    bool ece_flag;
    bool urg_flag;
    bool ack_flag;
    bool psh_flag;
    bool rst_flag;
    bool syn_flag;
    bool fin_flag;
    uint16_t window;
    uint16_t checksum;
    uint16_t urg_ptr;
    vector<uint8_t> options;

    size_t size() const { return data_offset*4; }
};

struct TcpDatagram
{
    TcpDatagram();
    TcpDatagram(const IpPacket& _ip_packet);

    IpPacketHeader ip_header;
    TcpDatagramHeader header;
    vector<uint8_t> data;
};

}

#endif // TCPDATAGRAM_H
