#include "httpheaderdetectorfactory.h"
#include "httpheaderdetector.h"

namespace HttpSniffer
{

HttpHeaderDetectorFactory::HttpHeaderDetectorFactory()
{
}

HttpHeaderDetectorFactory::~HttpHeaderDetectorFactory()
{

}

shared_ptr<TcpStreamDataHandler> HttpHeaderDetectorFactory::get_data_handler()
{
    //return make_shared<HttpHeaderDetector>();
    return shared_ptr<HttpHeaderDetector>(new HttpHeaderDetector);
}

}
