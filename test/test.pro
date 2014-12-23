TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
#QMAKE_CXXFLAGS += -std=c++03

SOURCES += main.cpp \
    /usr/local/include/gtest/gtest-all.cc \
    ../ippacketreassembler.cpp \
    ../Models/ippacket.cpp \
    ../Exceptions/ippacketreassemblerexcetions.cpp

HEADERS += \
    ip_packet_reassembler_test.h

LIBS += -lpthread
LIBS += -lpcap
