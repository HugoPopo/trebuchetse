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
    texttarget=QImage(":/texture/Image/cible.jpg");
}


void Target::drawTarget()
{
    QOpenGLTexture* text1 = new QOpenGLTexture(texttarget);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();
    GLUquadric* disk = gluNewQuadric();
    gluQuadricTexture(disk,GL_TRUE);
    glPushMatrix();
        glColor3f(1, 1, 1);
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
    yTarget = (rand() % 250)-175;

}

void Target::setyTarget(int y){
    yTarget = y;
}

void Target::setxTarget(int x){
    xTarget = x;
}
