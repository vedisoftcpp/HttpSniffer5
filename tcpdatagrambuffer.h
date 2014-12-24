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

    void push_datagram(const TcpDatagram& tcp_datagram);
    vector<uint8_t> pop_data();

    void set_seq(uint32_t seq) { _current_seq = seq; }

private:
    deque<TcpDatagram> _buffer;
    uint32_t _current_seq;
};

}

#endif // TCPDATAGRAMBUFFER_H
