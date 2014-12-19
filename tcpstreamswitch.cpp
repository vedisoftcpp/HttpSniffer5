#include "tcpstreamswitch.h"

namespace HttpSniffer
{

TcpStreamSwitch::TcpStreamSwitch()
{
}

void TcpStreamSwitch::process_ip_packet(const IpPacket& ip_packet)
{
    TcpDatagram tcp_datagram(ip_packet);
    if (!((tcp_datagram.header.dst_port == 80) ||
          (tcp_datagram.header.src_port == 80)))
    {
        return;
    }

    TcpStreamId tcp_stream_id(tcp_datagram);

    if (tcp_datagram.header.fin_flag)
    {
        _data_handlers.erase(tcp_stream_id);
        _data_handlers.erase(tcp_stream_id.inverse());
        return;
    }

    if (tcp_datagram.header.syn_flag)
    {
        _data_handlers[tcp_stream_id] = _data_handler_factory->get_data_handler();
        _data_handlers[tcp_stream_id.inverse()] = _data_handler_factory->get_data_handler();
        return;
    }

    unordered_map<TcpStreamId, shared_ptr<TcpStreamDataHandler> >::iterator it = _data_handlers.find(tcp_stream_id);
    if (it != _data_handlers.end())
    {
        TcpStreamDataHandler& data_handler = *(it->second);
        data_handler.process(tcp_datagram.data);
    }
}

}