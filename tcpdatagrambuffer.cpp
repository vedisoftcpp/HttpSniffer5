#include "tcpdatagrambuffer.h"

namespace HttpSniffer
{

TcpDatagramBuffer::TcpDatagramBuffer()
{
}

struct datagram_ordering
{
    bool operator() (const TcpDatagram& d1, const TcpDatagram& d2) const
    {
        return d1.header.seq_number < d2.header.seq_number;
    }
};

void TcpDatagramBuffer::push_packet(const TcpDatagram& tcp_datagram)
{
    _buffer.push_back(tcp_datagram);
    sort(_buffer.begin(), _buffer.end(), datagram_ordering());
}

vector<uint8_t> TcpDatagramBuffer::pop_data()
{
    if (_buffer.empty())
        return vector<uint8_t>();

    if (_current_seq < _buffer[0].header.seq_number)
        return vector<uint8_t>();



    return vector<uint8_t>();
}

}
