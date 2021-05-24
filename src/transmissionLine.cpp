#include "transmissionLine.h"
#include "glLib.h"
#include <iostream>

TransmissionLine::TransmissionLine(std::pair<Router, Router> rp)
{
    routerPair = rp;
    textLen = 0;
    displayText = new unsigned char[textLen];
}

void TransmissionLine::render()
{
    glLib::drawLine(routerPair.first.getX(), routerPair.first.getY(), routerPair.second.getX(), routerPair.second.getY(), glLib::black);

    if (packetsOnLine.size())
    {
        //find out x,y of text
        GLfloat textX = (routerPair.first.getX() + routerPair.second.getX()) / 2.0f;
        GLfloat textY = (routerPair.first.getY() + routerPair.second.getY()) / 2.0f;

        //compute text by vector of packets on line
        textLen = packetsOnLine.size() * 2;
        displayText = new unsigned char[textLen];
        for (int i = 0; i < packetsOnLine.size(); i++)
        {
            displayText[2 * i] = packetsOnLine[i].getName();
            displayText[2 * i + 1] = packetsOnLine[i].getCounter() + '0';
        }
        
        //drawText using Library
        glRasterPos2f(textX, textY);

        for (int i = 0; i < textLen; i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, displayText[i]);
        }

        for (auto i = packetsOnLine.begin(); i != packetsOnLine.end(); i++)
        {
            Packet p = *i;
            if (p.getCounter() == 0)
                packetsOnLine.erase(i);
        }
    }
}

void TransmissionLine::addPacket(Packet p)
{
    //add a packet
    packetsOnLine.push_back(p);
}

bool TransmissionLine::match(std::pair<Router, Router> rp)
{
    return (routerPair.first.getName() == rp.first.getName() && routerPair.second.getName() == rp.second.getName());
}