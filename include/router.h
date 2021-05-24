#ifndef ROUTER_H
#define ROUTER_H
#include <GL/gl.h>
#include <string>
#include "packet.h"

class Router
{
    GLfloat x;
    GLfloat y;
    GLfloat radius;
    std::string name;
    public:
        Router();
        Router(GLfloat, GLfloat, std::string);
        GLfloat getX();
        GLfloat getY();
        std::string getName();
        void render();
};

#endif