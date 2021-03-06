#include "tcpstreamswitch.h"

namespace HttpSniffer
{

TcpStreamSwitch::TcpStreamSwitch()
{
}

TcpStreamSwitch::~TcpStreamSwitch()
{

}

void TcpStreamSwitch::process_ip_packet(const IpPacket& ip_packet)
{
    TcpDatagram tcp_datagram(ip_packet);
//    if (tcp_datagram.header.syn_flag)
//    {
//        std::cout << "SYN!!!\n";
//    }

    if (!((tcp_datagram.header.dst_port == 80) ||
          (tcp_datagram.header.src_port == 80)))
    {
        return;
    }

    TcpStreamId tcp_stream_id(tcp_datagram);

    //std::cout << _data_handlers.size() << "\n";

    if (tcp_datagram.header.fin_flag)
    {
        map<TcpStreamId, TcpStreamDataHandler*>::iterator it = _data_handlers.find(tcp_stream_id);
        if (it != _data_handlers.end())
        {
            delete _data_handlers[tcp_stream_id];
            _data_handlers.erase(tcp_stream_id);
        }

        it = _data_handlers.find(tcp_stream_id.inverse());
        if (it != _data_handlers.end())
        {
            delete _data_handlers[tcp_stream_id.inverse()];
            _data_handlers.erase(tcp_stream_id.inverse());
        }

        return;
    }

    if (tcp_datagram.header.syn_flag)
    {
        map<TcpStreamId, TcpStreamDataHandler*>::iterator it = _data_handlers.find(tcp_stream_id);
        if (it != _data_handlers.end())
        {
            delete _data_handlers[tcp_stream_id];
            _data_handlers.erase(tcp_stream_id);
        }

        _data_handlers[tcp_stream_id] = _data_handler_factory->get_data_handler();
        _data_handlers[tcp_stream_id]->set_seq(tcp_datagram.header.seq_number + 1);
        _data_handlers[tcp_stream_id]->set_syn();
        return;
    }

    if (tcp_datagram.data.empty())
        return;

    map<TcpStreamId, TcpStreamDataHandler*>::iterator it = _data_handlers.find(tcp_stream_id);
    if (it != _data_handlers.end())
    {
        TcpStreamDataHandler& data_handler = *(it->second);
        if (data_handler.was_syn())
        {
            data_handler.process(tcp_datagram);
        }
        else
        {
            delete _data_handlers[tcp_stream_id];
            _data_handlers[tcp_stream_id] = _data_handler_factory->get_data_handler();
            _data_handlers[tcp_stream_id]->set_seq(tcp_datagram.header.seq_number);
            _data_handlers[tcp_stream_id]->process(tcp_datagram);
        }
    }
    else
    {
        //std::cout << "test\n";
        _data_handlers[tcp_stream_id] = _data_handler_factory->get_data_handler();
        _data_handlers[tcp_stream_id]->set_seq(tcp_datagram.header.seq_number);
        _data_handlers[tcp_stream_id]->process(tcp_datagram);
    }
}

}
