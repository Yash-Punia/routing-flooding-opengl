#ifndef PACKET_H
#define PACKET_H

class Packet
{
    char name;
    int counter;
    public:
        Packet();
        void updateCounter();
        char getName();
        int getCounter();
};

#endif