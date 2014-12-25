#TEMPLATE = app
#CONFIG += console
#CONFIG -= app_bundle

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \ #main.cpp \
    ippacketreassembler.cpp \
    ippacketreciever.cpp \
    tcpstreamswitch.cpp \
    tcpstreamdatahandler.cpp \
    httpheaderdetector.cpp \
    tcpstreamdatahandlerfactory.cpp \
    httpheaderdetectorfactory.cpp \
    Models/ippacket.cpp \
    Models/tcpdatagram.cpp \
    pcapippacketreciever.cpp \
    urlejector.cpp \
    Exceptions/ippacketreassemblerexcetions.cpp \
    tcpdatagrambuffer.cpp

HEADERS += \
    ippacketreassembler.h \
    ippacketreciever.h \
    tcpstreamswitch.h \
    tcpstreamdatahandler.h \
    httpheaderdetector.h \
    headers.h \
    tcpstreamdatahandlerfactory.h \
    httpheaderdetectorfactory.h \
    Models/ippacket.h \
    Models/tcpdatagram.h \
    pcapippacketreciever.h \
    urlejector.h \
    Exceptions/ippacketreassemblerexcetions.h \
    tcpdatagrambuffer.h

#win32 {
#INCLUDEPATH += $$PWD/../../Local/Include
#LIBS += -L$$PWD/../../Local/Lib/ -lwpcap
#}
#INCLUDEPATH += C:\Users\denism\Local\Include

LIBS += -lpcap

#system("cp /home/vedisoft/local/include/http_sniffer")

#system("mkdir /home/vedisoft/local/include/http_sniffer")
#system("for file in $$HEADERS; do cp "$file" /home/vedisoft/local/include/http_sniffer ; done")
