#ifndef TCP_STREAM_SWITCH_TEST_H
#define TCP_STREAM_SWITCH_TEST_H

#include <gtest/gtest.h>

#include "../headers.h"
#include "../tcpstreamdatahandler.h"
#include "../tcpstreamdatahandlerfactory.h"

using namespace HttpSniffer;

class FakeDataHandler : public TcpStreamDataHandler
{
public:
    FakeDataHandler()
    {

    }

    ~FakeDataHandler()
    {

    }

    void process_data(const vector<uint8_t>& data)
    {

    }
};

class FakeDataHandlerFactory : public TcpStreamDataHandlerFactory
{
public:
    FakeDataHandlerFactory()
    {

    }

    ~FakeDataHandlerFactory()
    {

    }

    shared_ptr<TcpStreamDataHandler> get_data_handler()
    {
        return shared_ptr<TcpStreamDataHandler>(new FakeDataHandler);
    }
};

#endif // TCP_STREAM_SWITCH_TEST_H
