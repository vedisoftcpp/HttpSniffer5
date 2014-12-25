#ifndef TCPSTREAMDATAHANDLERFACTORY_H
#define TCPSTREAMDATAHANDLERFACTORY_H

#include "headers.h"
#include "tcpstreamdatahandler.h"

namespace HttpSniffer
{

class TcpStreamDataHandlerFactory
{
public:
    TcpStreamDataHandlerFactory();
    virtual ~TcpStreamDataHandlerFactory();

    virtual TcpStreamDataHandler* get_data_handler() = 0;
};

}

#endif // TCPSTREAMDATAHANDLERFACTORY_H
