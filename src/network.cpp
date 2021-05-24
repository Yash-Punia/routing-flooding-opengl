#include "network.h"
#include <vector>
#include <algorithm>
/**
 * Add a router to the network
 * 
 * @param vector<Router> you want to add to the network
 */
void Network::addRouterToNetwork(std::vector<Router> r)
{
    routers.push_back(r);
    if (activeRouters.empty())
    {
        activeRouters.push(r[0]);
    }
}

/**
 * Connects 2 routers in our network undirectedly
 * 
 * @param vector<Router> Router one of the connection
 * @param vector<Router> Router two of the connection
 */
void Network::connectRouters(Router r1, Router r2)
{
    for (auto &router : routers)
    {
        if (router[0].getName() == r1.getName())
        {
            router.push_back(r2);
        }
        if (router[0].getName() == r2.getName())
        {
            router.push_back(r1);
        }
    }
    TransmissionLine line(std::make_pair(r1, r2));
    lines.push_back(line);
}

void Network::display()
{
    /// DISPLAY ALL THE LINES
    for (auto &line : lines)
    {
        line.render();
    }

    /// DISPLAY ALL THE ROUTERS
    for (auto &router : routers)
    {
        router[0].render();
    }
}

void Network::flood(Packet &packet)
{
    std::vector<Router> currentActiveRouters;
    while (!activeRouters.empty())
    {
        currentActiveRouters.push_back(activeRouters.top());
        activeRouters.pop();
    }
    if (packet.getCounter() > 0)
    {
        for (auto &incomingRouter : currentActiveRouters)
        {
            visitedRouters.push_back(incomingRouter);
            for (auto &router : routers)
            {
                if (router[0].getName() == incomingRouter.getName())
                {
                    for (int i = 1; i < router.size(); i++)
                    {
                        activeRouters.push(router[i]);
                        // if( !isVisited(router[i]) )
                            updateLine(router[i], incomingRouter, packet);
                    }
                }
            }
        }
        packet.updateCounter();
    }
}

void Network::updateLine(Router r1, Router r2, Packet packet)
{
    // go through each line in lines vector
    for (auto &line : lines)
    {
        // if found the line which has the same routers
        if (line.match(std::make_pair(r1, r2)) || line.match(std::make_pair(r2, r1)))
        {
            line.addPacket(packet);
        }
    }
}

bool Network::isVisited(Router r)
{
    for(auto router:visitedRouters)
    {
        if(router.getName() == r.getName())
            return true;
    }
    return false;
}