#ifndef HTTPHEADERDETECTORFACTORY_H
#define HTTPHEADERDETECTORFACTORY_H

#include "headers.h"
#include "tcpstreamdatahandlerfactory.h"

namespace HttpSniffer
{

class HttpHeaderDetectorFactory : public TcpStreamDataHandlerFactory
{
public:
    HttpHeaderDetectorFactory(vector<string>& urls);
    ~HttpHeaderDetectorFactory();

    TcpStreamDataHandler* get_data_handler();

private:
    vector<string>* _urls;
};

}

#endif // HTTPHEADERDETECTORFACTORY_H
