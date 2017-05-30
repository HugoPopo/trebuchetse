#include "target.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ESCAPE_KEY 27
#define PI 3.1415927


Target::Target()
{

}


void Target::drawTarget()
{
    GLUquadric* disk = gluNewQuadric();
    glPushMatrix();
        glColor3f(1, 0.4, 0.4);
        glTranslatef(xTarget, yTarget, 0.1);
        glScalef(50,50,1);
        gluDisk(disk, 0,1, 32,1);
    glPopMatrix();

}


