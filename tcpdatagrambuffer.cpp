#include "tcpdatagrambuffer.h"

namespace HttpSniffer
{

TcpDatagramBuffer::TcpDatagramBuffer() :
    _current_seq(0)
{
}

struct datagram_ordering
{
    bool operator() (const TcpDatagram& d1, const TcpDatagram& d2) const
    {
        return d1.header.seq_number < d2.header.seq_number;
    }
};

void TcpDatagramBuffer::push_datagram(const TcpDatagram& tcp_datagram)
{
    _buffer.push_back(tcp_datagram);
    sort(_buffer.begin(), _buffer.end(), datagram_ordering());
}

vector<uint8_t> TcpDatagramBuffer::pop_data()
{
    if (_buffer.empty())
        return vector<uint8_t>();

    vector<uint8_t> data;

    size_t i;
    for (i = 0; i < _buffer.size(); ++i)
    {
        if (_current_seq < _buffer[i].header.seq_number)
            break;

        if (_current_seq == _buffer[i].header.seq_number)
        {
            data.insert(data.end(), _buffer[i].data.begin(), _buffer[i].data.end());
            _current_seq += _buffer[i].data.size();
            continue;
        }

        if (_current_seq > _buffer[i].header.seq_number)
        {
            if (_current_seq >= _buffer[i].header.seq_number + _buffer[i].data.size())
                continue;

            data.insert(data.end(),
                        _buffer[i].data.begin() + (_current_seq - _buffer[i].header.seq_number),
                        _buffer[i].data.end());
            continue;
        }
    }

    _buffer.erase(_buffer.begin(),
                  _buffer.begin() + i);

    return data;
}

}
