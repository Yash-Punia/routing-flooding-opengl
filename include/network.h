#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <stack>
#include "transmissionLine.h"
#include <unistd.h> // for time delays

class Network
{
    /// adjacency list to represent graph using vectors
    std::vector<std::vector<Router>> routers;
    std::vector<TransmissionLine> lines;
    std::stack<Router> activeRouters;
    std::vector<Router> visitedRouters;

    void updateLine(Router, Router, Packet);
    bool isVisited(Router);

public:
    void addRouterToNetwork(std::vector<Router>);
    void connectRouters(Router, Router);
    void display();
    void flood(Packet &);
};

#endif