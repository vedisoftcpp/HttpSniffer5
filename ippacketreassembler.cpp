#include "ippacketreassembler.h"

namespace HttpSniffer
{

IpPacketReassembler::IpPacketReassembler()
{
}

bool is_ip_packet_fragmented(const IpPacket& ip_packet)
{
    if (ip_packet.header.dont_fragment)
    {
        //std::cout << "ip_packet.header.dont_fragment\n";
        return false;
    }

    if (!ip_packet.header.more_fragments && (ip_packet.header.fragment_offset == 0))
    {
        //std::cout << "ip_packet.header.more_fragments\n";
        return false;
    }

    return true;
}

struct fragmented_ordering
{
    bool operator() (const IpPacket& p1, const IpPacket& p2) const
    {
        return p1.header.fragment_offset < p2.header.fragment_offset;
    }
};

IpPacket IpPacketReassembler::reassemble(const IpPacket& ip_packet)
{
    if ( !is_ip_packet_fragmented(ip_packet) )
        return ip_packet;

    // have all ip-packets was recived
    unordered_map<uint32_t, vector<IpPacket> >::iterator it = _fragmented_packets.find(ip_packet.header.id);
    if (it == _fragmented_packets.end())
    {
        // there aren't ip-packet with same id in buffer
        vector<IpPacket> fragmented_packets;
        fragmented_packets.push_back(ip_packet);
        _fragmented_packets[ip_packet.header.id] = fragmented_packets;
        //throw IpPacketIsFragmentedException();
        //std::cout << "1\n";
        throw 1;
    }
    else
    {
        // there are ip-packet with same id in buffer

        // fragmented packets (fpackets)
        vector<IpPacket>& fragmented_packets = _fragmented_packets[ip_packet.header.id];

        fragmented_packets.push_back(ip_packet);
        sort(fragmented_packets.begin(), fragmented_packets.end(), fragmented_ordering());

        // try to merge
        IpPacket& first_packet = fragmented_packets[0];

        // fragment offset
        if (first_packet.header.fragment_offset)
        {
            // there isn't first packet
            //throw ThereIsNotFirstIpPacketException();
            //std::cout << "2\n";
            throw 1;
        }

        bool more_fragments = true;
        u_short data_length = first_packet.data.size();;
        vector<IpPacket>::iterator it;
        for (it = fragmented_packets.begin()+1; it != fragmented_packets.end(); ++it)
        {
            IpPacket& _ip_packet = *it;

            if (_ip_packet.header.fragment_offset != data_length/8)
            {
                // not all packets was recived
                //throw NotAllIpPacketsWasRecivedException;
                //std::cout << "3\n";
                throw 1;
            }

            data_length += _ip_packet.data.size();
            more_fragments = more_fragments && _ip_packet.header.more_fragments;
        }
        if (more_fragments)
        {
            // there isn't last packet
            //throw ThereIsNotLastIpPacketException;
            //std::cout << "4\n";
            throw 1;
        }

        // now we can merge fragmented packets

        // first packet header length + common data length
        first_packet.header.total_length = first_packet.header.size() + data_length;

        for (it = fragmented_packets.begin()+1; it != fragmented_packets.end(); ++it)
        {
            IpPacket& _ip_packet = *it;
            first_packet.data.insert(first_packet.data.begin(),
                                     _ip_packet.data.begin(),
                                     _ip_packet.data.end());
        }

        // merge first packet data and rest data
        IpPacket merged_ip_packet = first_packet;

        _fragmented_packets.erase(ip_packet.header.id);
        return merged_ip_packet;
    }
}

}
