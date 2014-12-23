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

private:
    TcpDatagramBuffer _tcp_datagram_buffer;
};

}

#endif // TCPSTREAMDATAHANDLER_H
