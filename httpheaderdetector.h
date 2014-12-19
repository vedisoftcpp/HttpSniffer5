#ifndef HTTPHEADERDETECTOR_H
#define HTTPHEADERDETECTOR_H

#include "headers.h"
#include "tcpstreamdatahandler.h"
#include "urlejector.h"

namespace HttpSniffer
{

class HttpHeaderDetector : public TcpStreamDataHandler
{
public:
    HttpHeaderDetector();

    void process(const vector<uint8_t>& data);

private:
    UrlEjector _url_ejector;
};

}

#endif // HTTPHEADERDETECTOR_H
