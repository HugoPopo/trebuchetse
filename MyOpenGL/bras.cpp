#include "bras.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>

Bras::Bras()
{

}
void Bras::poutre()
{

        //Partie Droite
        glPushMatrix();
            glTranslatef(0, 0, 0.125);
            glScalef (3,0.125, 0.125);
            drawCube(204,102,0);
        glPopMatrix();
}
void Bras::drawBras(){

    glPushMatrix();//P
        glRotatef(inclinaison,0,1,0);
        glTranslatef(1.25,0.25,2.75);
        glPushMatrix();//P
            glTranslatef(1,0,0);
            glPushMatrix();//P
                glScalef(1.5,1,1);
                poutre();
            glPopMatrix();//PP
            glPushMatrix();//P
                glTranslatef(2,0,0);

            glPopMatrix();//PP
        glPopMatrix();//PP
    glPopMatrix();//PP

}
