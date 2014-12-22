#include "urlejector.h"

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
    for (size_t pos = header.find("Host: ");
         pos != string::npos;
         pos = header.find("Host: ", pos+6))
    {
        size_t eol = header.find("\r\n", pos);
        if (eol == string::npos)
            return;
        string url(header.begin()+pos+6, header.begin()+eol);
        //buffer.push_back(url);
        std::cout << url << "\n";
        header.erase(header.begin(), header.begin()+eol);
    }
}

}
