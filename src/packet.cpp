#include "packet.h"

Packet::Packet()
{
    name='p';
    counter=3;
}

int Packet::getCounter()
{
    return counter;
}

char Packet::getName()
{
    return name;
}

void Packet::updateCounter()
{
    counter--;
}