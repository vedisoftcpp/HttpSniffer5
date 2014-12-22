#ifndef PCAPIPPACKETRECIEVER_H
#define PCAPIPPACKETRECIEVER_H

#include "headers.h"
#include "ippacketreciever.h"

namespace HttpSniffer
{

class PcapIpPacketReciever : public IpPacketReciever
{
public:
    PcapIpPacketReciever();
    ~PcapIpPacketReciever();

    void init();
    IpPacket get_ip_packet();

private:
    pcap_t* _adhandle;
};

}

#endif // PCAPIPPACKETRECIEVER_H
