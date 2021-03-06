#ifndef HTTP_SNIFFER_HEADERS_H
#define HTTP_SNIFFER_HEADERS_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <deque>
#include <map>

//#ifdef __unix__

//    #include "posix/thread.hpp"
//    #include "posix/mutex.h"
//    #include "posix/socket.h"

//#elif defined(_WIN32) || defined(WIN32)

//    #include <WinSock2.h>
//    #include <ws2tcpip.h>
//    #pragma comment(lib, "Ws2_32.lib")
//    #define HAVE_REMOTE 1
//    #include <pcap.h>

    //#include "win32/thread.hpp"
    //#include "win32/mutex.h"
    //#include "win32/socket.h"

//#endif

#include <sys/socket.h>
#include <netinet/in.h>
#define HAVE_REMOTE 1
#define WPCAP 1
#include <pcap.h>

typedef u_int8_t uint8_t;
typedef u_int16_t uint16_t;
typedef u_int32_t uint32_t;
typedef u_int64_t uint64_t;

//#include <tr1/memory>

namespace HttpSniffer
{
//using std::tr1::shared_ptr;
using std::vector;
using std::string;
using std::sort;
using std::deque;
using std::map;

class TcpStreamId;
struct IpPacket;
struct TcpDatagram;

}

#endif // HEADERS_H
