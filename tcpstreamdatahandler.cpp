#include "tcpstreamdatahandler.h"

namespace HttpSniffer
{

size_t TcpStreamDataHandler::counter = 0;

TcpStreamDataHandler::TcpStreamDataHandler() :
    _id(counter++)
{
}

TcpStreamDataHandler::~TcpStreamDataHandler()
{

}

void TcpStreamDataHandler::process(const TcpDatagram& tcp_datagram)
{
    if (!tcp_datagram.data.empty())
    {
        _tcp_datagram_buffer.push_datagram(tcp_datagram);
        process_data(_tcp_datagram_buffer.pop_data());
    }
    //std::cout << "id=" << _id << "; seq=" << tcp_datagram.header.seq_number << "\n\n";
}

}
