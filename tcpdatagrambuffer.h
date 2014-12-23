#ifndef TCPDATAGRAMBUFFER_H
#define TCPDATAGRAMBUFFER_H

#include "headers.h"
#include "Models/tcpdatagram.h"

namespace HttpSniffer
{

class TcpDatagramBuffer
{
public:
    TcpDatagramBuffer();

    void push_packet(const TcpDatagram& tcp_datagram);
    vector<uint8_t> pop_data();

private:
    vector<TcpDatagram> _buffer;
    uint32_t _current_seq;
};

}

#endif // TCPDATAGRAMBUFFER_H
