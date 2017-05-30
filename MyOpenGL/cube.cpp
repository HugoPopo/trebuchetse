#include "cube.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>


Cube::Cube()
{
    void drawCube(int R, int G,int B);

}

void Cube::drawCube(int R,int G,int B)
{

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

void Cube::drawCubeTexture()
{

    glBegin(GL_QUADS);

        //face 1

        glTexCoord2f (0,0);
        glVertex3d(1,1,1);
        glTexCoord2f(0,1);
        glVertex3d(1,1,-1);
        glTexCoord2f(1,1);
        glVertex3d(-1,1,-1);
        glTexCoord2f (1,0);
        glVertex3d(-1,1,1);
    glEnd();
        //face 2
    glBegin(GL_QUADS);

        glTexCoord2f (0,0);
        glVertex3d(1,-1,1);
        glTexCoord2f (0,1);
        glVertex3d(1,-1,-1);
        glTexCoord2f (1,1);
        glVertex3d(1,1,-1);
        glTexCoord2f (1,0);
        glVertex3d(1,1,1);

        glEnd();
        //face 3
        glBegin(GL_QUADS);

        glTexCoord2f (0,0);
        glVertex3d(-1,-1,1);
        glTexCoord2f (0,1);
        glVertex3d(-1,-1,-1);
        glTexCoord2f (1,1);
        glVertex3d(1,-1,-1);
        glTexCoord2f (1,0);
        glVertex3d(1,-1,1);

        glEnd();
        //face 4
        glBegin(GL_QUADS);

        glTexCoord2f (0,0);
        glVertex3d(-1,1,1);
        glTexCoord2f (0,1);
        glVertex3d(-1,1,-1);
        glTexCoord2f (1,1);
        glVertex3d(-1,-1,-1);
        glTexCoord2f (1,0);
        glVertex3d(-1,-1,1);

        glEnd();
        //face 5
        glBegin(GL_QUADS);

        glTexCoord2f (0,0);
        glVertex3d(1,1,-1);
        glTexCoord2f (0,1);
        glVertex3d(1,-1,-1);
        glTexCoord2f (1,1);
        glVertex3d(-1,-1,-1);
        glTexCoord2f (1,0);
        glVertex3d(-1,1,-1);

        glEnd();
        //face 6
        glBegin(GL_QUADS);

        glTexCoord2f (0,0);
        glVertex3d(1,-1,1);
        glTexCoord2f (0,1);
        glVertex3d(1,1,1);
        glTexCoord2f (1,1);
        glVertex3d(-1,1,1);
        glTexCoord2f (1,0);
        glVertex3d(-1,-1,1);

        glEnd();
}

