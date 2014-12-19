#ifndef HEADERS_H
#define HEADERS_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>

#ifdef __unix__

    #include "posix/thread.hpp"
    #include "posix/mutex.h"
    #include "posix/socket.h"

#elif defined(_WIN32) || defined(WIN32)

    #include <WinSock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")
    #define HAVE_REMOTE 1
    #include <pcap.h>
    //#include "win32/thread.hpp"
    //#include "win32/mutex.h"
    //#include "win32/socket.h"

#endif

namespace HttpSniffer
{

using std::tr1::shared_ptr;
using std::tr1::make_shared;
using std::vector;
using std::tr1::unordered_map;
using std::string;

using std::sort;

class TcpStreamId;
struct IpPacket;
struct TcpDatagram;

}

#endif // HEADERS_H
