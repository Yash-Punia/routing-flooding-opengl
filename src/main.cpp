#include <iostream>
#include <vector>
#include "network.h"
#include "glLib.h"

using namespace std;

void createNetwork();
void render();
void flood();

Network network;
vector<Router> routers;
Packet p;

GLint main(GLint argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Routing Using Flood");
    glLib::init();
    glutDisplayFunc(render);
    glutIdleFunc(flood);

    //Initialize flooding parameters
    createNetwork();

    glutMainLoop();
}

void createNetwork()
{
    int N = 5;
    string routerNames[] = {"A", "B", "C", "D", "E"};
    float distance = 150.0f;
    float routerX[] = {distance, 0.0f, -distance, -distance, distance};
    float routerY[] = {0.0f, distance, 0.0f, -distance, -distance};
    //INITIALIZE ALL THE ROUTERS OF OUR NETWORK
    for (int i = 0; i < N; i++)
    {
        routers.push_back(Router(routerX[i], routerY[i], routerNames[i]));
    }

    //ADD ROUTERS TO NETWORK
    for (int i = 0; i < N; i++)
    {
        vector<Router> r;
        r.push_back(routers[i]);
        network.addRouterToNetwork(r);
    }

    network.connectRouters(routers[0], routers[1]);
    network.connectRouters(routers[0], routers[2]);
    network.connectRouters(routers[0], routers[4]);
    network.connectRouters(routers[1], routers[2]);
    network.connectRouters(routers[2], routers[3]);
    network.connectRouters(routers[3], routers[4]);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //DISPLAY GRAPH WITH LATEST ROUTING
    network.display();

    glFlush();
}

void flood()
{
    sleep(1);
    network.flood(p);
    glutPostRedisplay();
}