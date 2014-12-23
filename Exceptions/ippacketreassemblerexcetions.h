#ifndef IPPACKETREASSEMBLEREXCETIONS_H
#define IPPACKETREASSEMBLEREXCETIONS_H

#include "../headers.h"
#include <exception>

namespace HttpSniffer
{

class BrokenIpPacketException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: broken ip packet.\n";
    }
};

class ThereAreNotAnotherIpPacketsException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: there are not another ip packets.\n";
    }
};

class ThereIsNotIpPacketWithZeroFragmentOffsetException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: there is not ip packet with zero fragment offset.\n";
    }
};

class NotAllIpPacketWereRecievedException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: not all ip packets was recieved.\n";
    }
};

class ThereIsNotLastIpPacketException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: there is not last ip packet.\n";
    }
};

extern BrokenIpPacketException broken_ip_packet_exception;
extern ThereAreNotAnotherIpPacketsException there_arent_another_ip_packets_exception;
extern ThereIsNotIpPacketWithZeroFragmentOffsetException there_isnt_ip_packet_with_0_fo_exception;
extern NotAllIpPacketWereRecievedException not_all_ip_packets_were_recieved_exception;
extern ThereIsNotLastIpPacketException there_isnt_last_ip_packet_exception;

}

#endif // IPPACKETREASSEMBLEREXCETIONS_H
