#ifndef TCPSTREAMSWITCH_H
#define TCPSTREAMSWITCH_H

#include "headers.h"
#include "tcpstreamdatahandler.h"
#include "tcpstreamdatahandlerfactory.h"
#include "Models/tcpdatagram.h"

namespace HttpSniffer
{

class TcpStreamId
{
public:
    friend struct std::tr1::hash<TcpStreamId>;

    TcpStreamId(uint32_t _src_addr, uint32_t _dst_addr, uint16_t _src_port, uint16_t _dst_port) :
        src_addr(_src_addr),
        dst_addr(_dst_addr),
        src_port(_src_port),
        dst_port(_dst_port)
    {

    }

    TcpStreamId(const TcpDatagram& tcp_datagram) :
        src_addr(tcp_datagram.ip_header.src_addr),
        dst_addr(tcp_datagram.ip_header.dst_addr),
        src_port(tcp_datagram.header.src_port),
        dst_port(tcp_datagram.header.dst_port)
    {

    }

    bool operator== (const TcpStreamId& id) const
    {
        if (src_addr != id.src_addr)
            return false;
        if (dst_addr != id.dst_addr)
            return false;
        if (src_port != id.src_port)
            return false;
        if (dst_port != id.dst_port)
            return false;
        return true;
    }

    TcpStreamId inverse()
    {
        return TcpStreamId(dst_addr, src_addr, dst_port, src_port);
    }

private:
    uint32_t src_addr;
    uint32_t dst_addr;
    uint16_t src_port;
    uint16_t dst_port;
};

}

//-----------------------------------------------



namespace std
{
namespace tr1
{

using HttpSniffer::TcpStreamId;

template <>
struct hash<TcpStreamId>
{
    std::size_t operator()(const TcpStreamId& id) const
    {
        using std::tr1::hash;

        size_t h1 = hash<uint32_t>()(id.src_addr);
        size_t h2 = hash<uint32_t>()(id.dst_addr);
        size_t h3 = hash<uint16_t>()(id.src_port);
        size_t h4 = hash<uint16_t>()(id.dst_port);

        return ((((h1 ^ (h3 << 1)) >> 1) ^ (h2 << 1)) >> 1) ^ (h4 << 1);
    }
};

}
}



//-----------------------------------------------

namespace HttpSniffer
{

class TcpStreamSwitch
{
public:
    TcpStreamSwitch();
    ~TcpStreamSwitch();

    void set_tcp_stream_handler_factory(TcpStreamDataHandlerFactory& data_handler_factory)
    {
        _data_handler_factory = &data_handler_factory;
    }

    void process_ip_packet(const IpPacket& ip_packet);

private:
    TcpStreamDataHandlerFactory* _data_handler_factory;
    unordered_map<TcpStreamId, shared_ptr<TcpStreamDataHandler> > _data_handlers;
};

}

#endif // TCPSTREAMSWITCH_H
