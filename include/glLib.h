#ifndef GL_LIB
#define GL_LIB
#include <GL/freeglut.h>

#define W 500
#define H 500

namespace glLib
{
    struct Color
    {
        GLfloat r;
        GLfloat g;
        GLfloat b;
    };

    extern Color red, green, blue, black, white;

    void init();
    void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, Color c);
    void drawCircle(GLfloat centerX, GLfloat centerY, GLfloat radius, Color c);
}

#endif