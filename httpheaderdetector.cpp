#include "httpheaderdetector.h"

namespace HttpSniffer
{

HttpHeaderDetector::HttpHeaderDetector()
{
}

HttpHeaderDetector::~HttpHeaderDetector()
{

}

void HttpHeaderDetector::process(const vector<uint8_t>& data)
{
    _data.insert(_data.end(), data.begin(), data.end());
    _url_ejector.eject(_data);
}

}
