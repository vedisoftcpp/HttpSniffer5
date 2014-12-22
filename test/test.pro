TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    /usr/local/include/gtest/gtest-all.cc

HEADERS += \
    ip_packet_reassembler_test.h

LIBS += -lpthread
LIBS += -lpcap
