#ifndef HTTPHEADERDETECTORFACTORY_H
#define HTTPHEADERDETECTORFACTORY_H

#include "headers.h"
#include "tcpstreamdatahandlerfactory.h"

namespace HttpSniffer
{

class HttpHeaderDetectorFactory : public TcpStreamDataHandlerFactory
{
public:
    HttpHeaderDetectorFactory();

    shared_ptr<TcpStreamDataHandler> get_data_handler();
};

}

#endif // HTTPHEADERDETECTORFACTORY_H
