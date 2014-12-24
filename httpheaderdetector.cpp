#include "httpheaderdetector.h"

namespace HttpSniffer
{

HttpHeaderDetector::HttpHeaderDetector() :
    TcpStreamDataHandler()
{
}

HttpHeaderDetector::~HttpHeaderDetector()
{

}

void HttpHeaderDetector::process_data(const vector<uint8_t>& data)
{
    _data.insert(_data.end(), data.begin(), data.end());
    _url_ejector.eject(_data);
}

}
