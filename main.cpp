#include "headers.h"
#include "httpheaderdetectorfactory.h"
#include "tcpstreamswitch.h"
#include "pcapippacketreciever.h"

using namespace HttpSniffer;

int main()
{
    vector<string> urls;
    PcapIpPacketReciever ip_packet_reciever;
    TcpStreamSwitch tcp_stream_switch;
    HttpHeaderDetectorFactory http_header_detector_factory(urls);
    tcp_stream_switch.set_tcp_stream_handler_factory(http_header_detector_factory);
    ip_packet_reciever.set_tcp_stream_switch(tcp_stream_switch);
    //ip_packet_reciever.run();
    ip_packet_reciever.init();
    while (true)
    {
        ip_packet_reciever.work();
        if (!urls.empty())
        {
            for (vector<string>::iterator it = urls.begin(); it != urls.end(); ++it)
                std::cout << *it << "\n";
            urls.clear();
        }
    }
    return 0;
}

