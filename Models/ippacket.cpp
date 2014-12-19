#include "ippacket.h"

namespace HttpSniffer
{


IpPacketHeader::IpPacketHeader()
{

}

IpPacketHeader::IpPacketHeader(ip_header_t* ip_header) :
    version(ip_header->ver_ihl >> 4),
    ihl(ip_header->ver_ihl & 0x0f),
    dscp(ip_header->tos >> 2),
    ecn(ip_header->tos & 0x03),
    total_length(ntohs(ip_header->tlen)),
    id(ntohs(ip_header->identification)),
    dont_fragment(((ntohs(ip_header->flags_fo) >> 13) & 0x02) != 0),
    more_fragments(((ntohs(ip_header->flags_fo) >> 13) & 0x01) != 0),
    fragment_offset(ntohs(ip_header->flags_fo) & 0x1fff),
    ttl(ip_header->ttl),
    protocol(ip_header->proto),
    crc(ip_header->crc),
    src_addr(ntohl(*((uint32_t*)(&ip_header->saddr)))),
    dst_addr(ntohl(*((uint32_t*)(&ip_header->daddr))))
{
    for (size_t i = 20; i < size(); ++i)
    {
        options.push_back( *((uint8_t*)ip_header + i) );
    }
}

IpPacket::IpPacket()
{

}

IpPacket::IpPacket(void* ip_ptr) :
    header((ip_header_t*)ip_ptr)
{
    for (size_t i = header.size(); i < header.total_length; ++i)
    {
        data.push_back( *((uint8_t*)ip_ptr + i) );
    }
}


}
