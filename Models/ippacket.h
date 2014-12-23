#ifndef IPPACKET_H
#define IPPACKET_H

#include "../headers.h"

namespace HttpSniffer
{

struct ip_address_t
{
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
    uint8_t byte4;
};

struct ip_header_t
{
    uint8_t  ver_ihl;        // Version (4 bits) + Internet header length (4 bits)
    uint8_t  tos;            // Type of service
    uint16_t tlen;           // Total length
    uint16_t identification; // Identification
    uint16_t flags_fo;       // Flags (3 bits) + Fragment offset (13 bits)
    uint8_t  ttl;            // Time to live
    uint8_t  proto;          // Protocol
    uint16_t crc;            // Header checksum
    ip_address_t  saddr;    // Source address
    ip_address_t  daddr;    // Destination address
    uint32_t   op_pad;         // Option + Padding
};

struct IpPacketHeader
{
    IpPacketHeader();
    IpPacketHeader(ip_header_t* ip_header);

    uint8_t version;
    uint8_t ihl;
    uint8_t dscp;
    uint8_t ecn;
    uint16_t total_length;
    uint16_t id;
    bool dont_fragment;
    bool more_fragments;
    uint16_t fragment_offset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t crc;
    uint32_t src_addr;
    uint32_t dst_addr;
    vector<uint8_t> options;

    size_t size() const { return ihl * 4; }

    bool operator== (const IpPacketHeader& header) const
    {
        if (this == &header) return true;
        if (version != header.version) return false;
        if (ihl != header.ihl) return false;
        if (dscp != header.dscp) return false;
        if (ecn != header.ecn) return false;
        if (total_length != header.total_length) return false;
        if (id != header.id) return false;
        if (dont_fragment != header.dont_fragment) return false;
        if (more_fragments != header.more_fragments) return false;
        if (fragment_offset != header.fragment_offset) return false;
        if (ttl != header.ttl) return false;
        if (protocol != header.protocol) return false;
        if (crc != header.crc) return false;
        if (src_addr != header.src_addr) return false;
        if (dst_addr != header.dst_addr) return false;
        if (options != header.options) return false;
        return true;
    }

    bool operator!= (const IpPacketHeader& header) const
    {
        if (*this == header)
            return false;
        else
            return true;
    }
};

struct IpPacket
{
    IpPacket();
    IpPacket(void *ip_ptr);

    IpPacketHeader header;
    vector<uint8_t> data;

    bool operator== (const IpPacket& ip_packet) const
    {
        if (this == &ip_packet) return true;
        if (header != ip_packet.header) return false;
        if (data != ip_packet.data) return false;
        return true;
    }

    bool operator!= (const IpPacket& ip_packet) const
    {
        if (*this == ip_packet)
            return false;
        else
            return true;
    }
};

}

#endif // IPPACKET_H
