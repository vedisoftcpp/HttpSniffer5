#ifndef TCP_DATAGRAM_BUFFER_TEST_H
#define TCP_DATAGRAM_BUFFER_TEST_H

#include <gtest/gtest.h>
#include "../tcpdatagrambuffer.h"
#include "../Models/tcpdatagram.h"

using namespace HttpSniffer;

TEST(TcpDatagramBufferTest, simple_push_datagram)
{
    TcpDatagram tcp_datagram;
    tcp_datagram.header.seq_number = 0;
    tcp_datagram.data.push_back(1);
    tcp_datagram.data.push_back(2);
    tcp_datagram.data.push_back(3);

    TcpDatagramBuffer buffer;
    buffer.push_datagram(tcp_datagram);

    vector<uint8_t> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);

    EXPECT_EQ(result, buffer.pop_data());
}

TEST(TcpDatagramBufferTest, datagram_has_additional_data)
{
    TcpDatagram tcp_datagram;
    tcp_datagram.header.seq_number = 0;
    tcp_datagram.data.push_back(1);
    tcp_datagram.data.push_back(2);
    tcp_datagram.data.push_back(3);

    TcpDatagramBuffer buffer;
    buffer.push_datagram(tcp_datagram);

    vector<uint8_t> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);

    buffer.pop_data();

    tcp_datagram.data.push_back(4);
    buffer.push_datagram(tcp_datagram);

    result.clear();
    result.push_back(4);

    EXPECT_EQ(result, buffer.pop_data());
}

TEST(TcpDatagramBufferTest, current_seq_less_that_all_datagrams_have)
{
    TcpDatagram tcp_datagram;
    tcp_datagram.header.seq_number = 0;
    tcp_datagram.data.push_back(1);
    tcp_datagram.data.push_back(2);
    tcp_datagram.data.push_back(3);

    TcpDatagramBuffer buffer;
    buffer.push_datagram(tcp_datagram);

    vector<uint8_t> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);

    buffer.pop_data();

    tcp_datagram.data.push_back(4);
    tcp_datagram.header.seq_number = 4;
    buffer.push_datagram(tcp_datagram);
    result.push_back(4);

    EXPECT_EQ(vector<uint8_t>(), buffer.pop_data());
}

TEST(TcpDatagramBufferTest, current_seq_isnt_equal_zero)
{
    TcpDatagram tcp_datagram;
    tcp_datagram.header.seq_number = 0;
    tcp_datagram.data.push_back(1);
    tcp_datagram.data.push_back(2);
    tcp_datagram.data.push_back(3);

    TcpDatagramBuffer buffer;
    buffer.push_datagram(tcp_datagram);

    vector<uint8_t> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(3);

    buffer.pop_data();

    tcp_datagram.data.push_back(4);
    tcp_datagram.header.seq_number = 3;
    buffer.push_datagram(tcp_datagram);
    result.push_back(4);

    EXPECT_EQ(result, buffer.pop_data());
}

#endif // TCP_DATAGRAM_BUFFER_TEST_H
