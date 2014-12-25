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
    virtual ~IpPacketReciever();

    void run();
    void work();
    virtual void init();
    virtual IpPacket get_ip_packet() = 0;

    void set_tcp_stream_switch(TcpStreamSwitch& tcp_stream_switch)
    {
        _tcp_stream_switch = &tcp_stream_switch;
    }

private:
    IpPacketReassembler _ip_packet_reassembler;
    TcpStreamSwitch* _tcp_stream_switch;
};

}

#endif // IPPACKETRECIEVER_H
