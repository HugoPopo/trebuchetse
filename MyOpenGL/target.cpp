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


void Target::lvlTarget(int level){
    srand (time(NULL));

    switch (level){
    case 1:
        xTarget = ((rand()%200) - 250);
        break;
    case 2:
        xTarget = ((rand()%200) - 50);
        break;
    case 3:
        xTarget = ((rand()%200) + 150);
        break;
    }
    yTarget = (rand() % 350)-175;

}

void Target::setyTarget(int y){
    yTarget = y;
}

void Target::setxTarget(int x){
    xTarget = x;
}
