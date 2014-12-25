#include "ippacketreciever.h"

namespace HttpSniffer
{

IpPacketReciever::IpPacketReciever()
{
}

IpPacketReciever::~IpPacketReciever()
{

}

void IpPacketReciever::init()
{

}

void IpPacketReciever::run()
{
    init();
    while (true)
    {
        IpPacket ip_packet = get_ip_packet();
        try
        {
            ip_packet = _ip_packet_reassembler.reassemble(ip_packet);
        }
        catch(...)
        {

        }
        _tcp_stream_switch->process_ip_packet(ip_packet);
    }
}

void IpPacketReciever::work()
{
    IpPacket ip_packet = get_ip_packet();
    try
    {
        ip_packet = _ip_packet_reassembler.reassemble(ip_packet);
    }
    catch(...)
    {

    }
    _tcp_stream_switch->process_ip_packet(ip_packet);
}

}
