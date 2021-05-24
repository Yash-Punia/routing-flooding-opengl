#include "glLib.h"
#include <cmath>

#define PI 3.14

glLib::Color glLib::red = {1.0f, 0.0f, 0.0f};
glLib::Color glLib::green = {0.0f, 1.0f, 0.0f};
glLib::Color glLib::blue = {0.0f, 0.0f, 1.0f};
glLib::Color glLib::black = {0.0f, 0.0f, 0.0f};
glLib::Color glLib::white = {1.0f, 1.0f, 1.0f};

/**
 * Draw line on window
 * 
 * Draws a line on the window with given coordinates and color provided
 * 
 * @param x1 x coordinate of start point 
 * @param y1 y coordinate of start point
 * @param x2 x coordinate of end point
 * @param y2 y coordinate of end point
 * @param color color of the line given in Color structure of glLib
 */
void glLib::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, glLib::Color col)
{
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

/**
 * Draw a circle on window
 * 
 * Draws a circle on the window with given (x,y) as center and filled with color provided
 * 
 * @param x1 x coordinate of center 
 * @param y1 y coordinate of center
 * @param radius radius of circle
 * @param color color of the circle to be filled in
 */
void glLib::drawCircle(GLfloat x, GLfloat y, GLfloat rad, glLib::Color col)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(col.r, col.g, col.b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (rad * cos(i * twicePi / triangleAmount)),
            y + (rad * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void glLib::init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-W / 2, W / 2, -H / 2, H / 2);
}