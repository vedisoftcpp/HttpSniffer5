#include "headers.h"
#include "httpheaderdetectorfactory.h"
#include "tcpstreamswitch.h"
#include "pcapippacketreciever.h"

using namespace HttpSniffer;

int main()
{
    PcapIpPacketReciever ip_packet_reciever;
    TcpStreamSwitch tcp_stream_switch;
    HttpHeaderDetectorFactory http_header_detector_factory;
    tcp_stream_switch.set_tcp_stream_handler_factory(http_header_detector_factory);
    ip_packet_reciever.set_tcp_stream_switch(tcp_stream_switch);
    ip_packet_reciever.run();
    return 0;
}

