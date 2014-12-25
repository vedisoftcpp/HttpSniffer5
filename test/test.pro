TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
#QMAKE_CXXFLAGS += -std=c++03

SOURCES += main.cpp \
    /usr/local/include/gtest/gtest-all.cc \
    ../ippacketreassembler.cpp \
    ../Models/ippacket.cpp \
    ../Exceptions/ippacketreassemblerexcetions.cpp \
    ../tcpstreamswitch.cpp \
    ../Models/tcpdatagram.cpp \
    ../tcpstreamdatahandlerfactory.cpp \
    ../tcpstreamdatahandler.cpp \
    ../tcpdatagrambuffer.cpp \
    ../urlejector.cpp

HEADERS += \
    ip_packet_reassembler_test.h \
    tcp_stream_switch_test.h \
    tcp_datagram_buffer_test.h \
    url_ejector_test.h

LIBS += -lpthread
LIBS += -lpcap
