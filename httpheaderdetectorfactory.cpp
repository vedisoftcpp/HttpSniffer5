#include "httpheaderdetectorfactory.h"
#include "httpheaderdetector.h"

namespace HttpSniffer
{

HttpHeaderDetectorFactory::HttpHeaderDetectorFactory(vector<string>& urls) :
    _urls(&urls)
{
}

HttpHeaderDetectorFactory::~HttpHeaderDetectorFactory()
{

}

TcpStreamDataHandler* HttpHeaderDetectorFactory::get_data_handler()
{
    //return make_shared<HttpHeaderDetector>();
    return new HttpHeaderDetector(*_urls);
}

}
