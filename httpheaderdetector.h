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
    HttpHeaderDetector(vector<string>& urls);
    ~HttpHeaderDetector();

    void process_data(const vector<uint8_t>& data);

private:
    UrlEjector _url_ejector;
    string _data;
    vector<string>* _urls;
};

}

#endif // HTTPHEADERDETECTOR_H
