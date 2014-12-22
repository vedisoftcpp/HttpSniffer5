#ifndef URLEJECTOR_H
#define URLEJECTOR_H

#include "headers.h"

namespace HttpSniffer
{

class UrlEjector
{
public:
    UrlEjector();
    ~UrlEjector();

    void eject(string& header);
};

}

#endif // URLEJECTOR_H
