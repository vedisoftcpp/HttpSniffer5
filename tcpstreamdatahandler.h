#ifndef TCPSTREAMDATAHANDLER_H
#define TCPSTREAMDATAHANDLER_H

#include "headers.h"

namespace HttpSniffer
{

class TcpStreamDataHandler
{
public:
    TcpStreamDataHandler();
    virtual ~TcpStreamDataHandler();

    virtual void process(const vector<uint8_t>& data) = 0;
};

}

#endif // TCPSTREAMDATAHANDLER_H
