#ifndef IPPACKETRECIEVER_H
#define IPPACKETRECIEVER_H

#include "headers.h"
#include "Models/ippacket.h"
#include "ippacketreassembler.h"
#include "tcpstreamswitch.h"

namespace HttpSniffer
{

class IpPacketReciever
{
public:
    IpPacketReciever();

    void run();
    virtual void init();
    virtual IpPacket get_ip_packet() = 0;

private:
    IpPacketReassembler _ip_packet_reassembler;
    TcpStreamSwitch _tcp_stream_switch;
};

}

#endif // IPPACKETRECIEVER_H
