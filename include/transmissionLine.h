#ifndef TRANSMISSION_LINE_H
#define TRANSMISSION_LINE_H
#include <vector>
#include "router.h"

class TransmissionLine
{
    std::pair<Router, Router> routerPair;
    std::vector<Packet> packetsOnLine;
    unsigned char *displayText;
    int textLen;
    public:
        TransmissionLine(std::pair<Router,Router>);
        void render();
        void addPacket(Packet);
        bool match(std::pair<Router,Router>);
};

#endif