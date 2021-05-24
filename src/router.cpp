#include "router.h"
#include "glLib.h"

Router::Router()
{
    x = 0;
    y = 0;
    name = "";
    radius = 20.0f;
}

Router::Router(GLfloat inX, GLfloat inY, std::string inputName)
{
    x = inX;
    y = inY;
    name = inputName;
    radius = 20.0f;
}

/**
 * Get X coordinate of Router
 * 
 * @return X coordinate of the Router
*/
GLfloat Router::getX()
{
    return x;
}

/**
 * Get Y coordinate of Router
 * 
 * @return Y coordinate of the Router
*/
GLfloat Router::getY()
{
    return y;
}

/**
 * Get Name (string) of Router
 * 
 * @return name of the Router
*/
std::string Router::getName()
{
    return name;
}

void Router::render()
{
    glLib::drawCircle(x,y,radius,glLib::red);
}