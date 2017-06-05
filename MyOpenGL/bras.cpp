#include "bras.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>

Bras::Bras()
{
    textbois=QImage(":/texture/Image/bois.jpg");
}

void Bras::drawContrepoid()
{
    QOpenGLTexture* text1 = new QOpenGLTexture(textbois);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();
    glColor3f(0.43, 0.35, 0.24);
        glPushMatrix();
            glTranslatef(0,0,-1);
            glScalef (0.5, 0.5, 0.5);
            drawCubeTexture();
       glPopMatrix();
}

void Bras::poutre()
{
    QOpenGLTexture* text1 = new QOpenGLTexture(textbois);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();

    glColor3f(1,1,1);
    glPushMatrix();
        glTranslatef(0, 0, 0.125);
        glScalef (3,0.125, 0.125);
        drawCubeTexture();
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
            glPushMatrix();
                        glTranslatef(-6,0,0);
                        glRotatef(inclinaison,0,-1,0);
                        drawContrepoid();
                    glPopMatrix();
            glPushMatrix();//P
                glTranslatef(8,0,0);
                //Line
                fil.drawLine();
            glPopMatrix();//PP
            glPushMatrix();//P
                //Boulet
                glTranslatef(9.5,0,0);
                boulet.drawBoulet();
            glPopMatrix();//PP
        glPopMatrix();//PP
    glPopMatrix();//PP

}
void Bras::setInclinaison(int inc){
    inclinaison=inc;
}
