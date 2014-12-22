#include "tcpdatagram.h"
#include "ippacket.h"

namespace HttpSniffer
{

TcpDatagramHeader::TcpDatagramHeader()
{

}

TcpDatagramHeader::TcpDatagramHeader(const tcp_header_t* th) :
    src_port(ntohs(th->src_port)),
    dst_port(ntohs(th->dst_port)),
    seq_number(ntohl(th->seq_number)),
    ask_number(ntohl(th->ask_number)),
    data_offset(th->stuff >> 4),
    ns_flag((th->stuff & 0x01) != 0),
    cwr_flag((th->flags & 0x80) != 0),
    ece_flag((th->flags & 0x40) != 0),
    urg_flag((th->flags & 0x20) != 0),
    ack_flag((th->flags & 0x10) != 0),
    psh_flag((th->flags & 0x8) != 0),
    rst_flag((th->flags & 0x4) != 0),
    syn_flag((th->flags & 0x2) != 0),
    fin_flag((th->flags & 0x1) != 0),
    window(ntohs(th->window)),
    checksum(ntohs(th->checksum)),
    urg_ptr(ntohs(th->urg_ptr))
{
    for (size_t i = 20; i < size(); ++i)
    {
       options.push_back( *((uint8_t*)th + i) );
    }
}

TcpDatagram::TcpDatagram()
{

}

TcpDatagram::TcpDatagram(const IpPacket& _ip_packet) :
    ip_header(_ip_packet.header),
    header((tcp_header_t*)&_ip_packet.data[0])
{
    for (size_t i = _ip_packet.header.size(); i < _ip_packet.data.size(); ++i)
    {
        data.push_back( *((uint8_t*)&_ip_packet.data[0] + i) );
    }
}

}
