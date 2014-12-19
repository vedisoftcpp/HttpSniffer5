#include "headers.h"
#include "httpheaderdetectorfactory.h"
#include "pcapippacketreciever.h"

using namespace HttpSniffer;

int main()
{
    PcapIpPacketReciever ip_packet_reciever;
    ip_packet_reciever.run();
    return 0;
}

