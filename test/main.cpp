#include <gtest/gtest.h>
#include "ip_packet_reassembler_test.h"
#include "tcp_stream_switch_test.h"
#include "tcp_datagram_buffer_test.h"
#include "url_ejector_test.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

