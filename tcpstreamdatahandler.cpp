#include "tcpstreamdatahandler.h"

namespace HttpSniffer
{

TcpStreamDataHandler::TcpStreamDataHandler()
{
}

TcpStreamDataHandler::~TcpStreamDataHandler()
{

}

void TcpStreamDataHandler::process(const TcpDatagram& tcp_datagram)
{
    _tcp_datagram_buffer.push_packet(tcp_datagram);
    process_data(_tcp_datagram_buffer.pop_data());
}

}
