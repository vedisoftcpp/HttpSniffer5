#include "httpheaderdetector.h"

namespace HttpSniffer
{

HttpHeaderDetector::HttpHeaderDetector(vector<string>& urls) :
    TcpStreamDataHandler(),
    _urls(&urls)
{
}

HttpHeaderDetector::~HttpHeaderDetector()
{

}

void HttpHeaderDetector::process_data(const vector<uint8_t>& data)
{
    _data.insert(_data.end(), data.begin(), data.end());
    _url_ejector.eject(_data);
    if (!_url_ejector.urls.empty())
    {
        _urls->insert(_urls->end(),
                      _url_ejector.urls.begin(),
                      _url_ejector.urls.end());
        _url_ejector.urls.clear();
    }
}

}
