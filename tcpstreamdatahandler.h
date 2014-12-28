#ifndef TCPSTREAMDATAHANDLER_H
#define TCPSTREAMDATAHANDLER_H

#include "headers.h"
#include "tcpdatagrambuffer.h"

namespace HttpSniffer
{

class TcpStreamDataHandler
{
public:
    TcpStreamDataHandler();
    virtual ~TcpStreamDataHandler();

    virtual void process_data(const vector<uint8_t>& data) = 0;
    void process(const TcpDatagram& tcp_datagram);

    size_t id() const { return _id; }
    void set_seq(uint32_t seq) { _tcp_datagram_buffer.set_seq(seq); }

    void set_syn() { _was_syn = true; }
    bool was_syn() const { return _was_syn; }

private:
    TcpDatagramBuffer _tcp_datagram_buffer;
    size_t _id;
    static size_t counter;
    bool _was_syn;
};

}

#endif // TCPSTREAMDATAHANDLER_H
