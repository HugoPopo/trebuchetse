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


target::target()
{

}


void target::drawTarget()
{
    glPushMatrix();
            glTranslatef(xTarget, yTarget, 25);
            glRotatef(60,0,1,0);
            glPushMatrix();
                glScalef(10,10,2);
                drawCube(255,255,0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,-0.1);
                glScalef(20,20,2);
                drawCube(255,100,0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,-0.2);
                glScalef(30,30,2);
                drawCube(255,0,255);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,-0.3);
                glScalef(50,50,2);
                drawCube(255,0,100);
            glPopMatrix();
        glPopMatrix();

}

void target::drawCube(int R,int G,int B){

        glBegin(GL_QUADS);

            glColor3ub(R, G, B); //face 1
            glVertex3d(1,1,1);
            glVertex3d(1,1,-1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,1,1);

            glColor3ub(R, G, B); //face 2
            glVertex3d(1,-1,1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,1,-1);
            glVertex3d(1,1,1);

            glColor3ub(R, G, B); //face 3
            glVertex3d(-1,-1,1);
            glVertex3d(-1,-1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(1,-1,1);

            glColor3ub(R, G, B); //face 4
            glVertex3d(-1,1,1);
            glVertex3d(-1,1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,-1,1);

            glColor3ub(R, G, B); //face 5
            glVertex3d(1,1,-1);
            glVertex3d(1,-1,-1);
            glVertex3d(-1,-1,-1);
            glVertex3d(-1,1,-1);

            glColor3ub(R, G, B); //face 6
            glVertex3d(1,-1,1);
            glVertex3d(1,1,1);
            glVertex3d(-1,1,1);
            glVertex3d(-1,-1,1);

            glEnd();
    }

