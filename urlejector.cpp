#include "urlejector.h"
#include <string.h>

namespace HttpSniffer
{

UrlEjector::UrlEjector()
{
}

UrlEjector::~UrlEjector()
{

}

void UrlEjector::eject(string& header)
{
//    const char * search_string = "Host: ";
//    for (size_t pos = header.find(search_string);
//         pos != string::npos;
//         pos = header.find("Host: ", pos))
//    {
//        size_t eol = header.find("\r\n", pos);
//        if (eol == string::npos)
//            return;
//        string url(header.begin()+pos+strlen(search_string), header.begin()+eol);
//        urls.push_back(url);
//        header.erase(header.begin(), header.begin()+eol);
//    }

    for (size_t pos = header.find("GET ");
         pos != string::npos;
         pos = header.find("GET ", pos+4))
    {
        size_t eol = header.find(" HTTP", pos);
        if (eol == string::npos)
            return;
        string url(header.begin()+pos+4, header.begin()+eol);

        size_t pos1 = header.find("Host: ", pos);
        if (pos1 == string::npos)
            return;
        eol = header.find("\r\n", pos1);
        if (eol == string::npos)
            return;

        string host(header.begin()+pos1+6, header.begin()+eol);

        urls.push_back(host+url);

        header.erase(header.begin()+pos, header.begin()+eol);
    }
}

}
