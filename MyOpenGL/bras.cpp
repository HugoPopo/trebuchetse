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
    pointf2 = 0;
    pointf3 = 0;
    pointf4 = 0;
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
void Bras::drawBras(float pointf2,float pointf3,float pointf4){

    glPushMatrix();//P
        glRotatef(inclinaison,0,1,0);
        //glTranslatef(1.25,0.25,2.75);
        glPushMatrix();//P
            glTranslatef(2,0,0);
            glPushMatrix();//P
                glScalef(1.5,1,1);
                poutre();
            glPopMatrix();//PP
            glPushMatrix();
                        glTranslatef(-4.2,0,1);
                        //glRotatef(inclinaison,0,-1,0);
                        drawContrepoid();
                    glPopMatrix();
            glPushMatrix();//P
                glTranslatef(4,0,0);
                glRotatef(150,0,1,0);
                glTranslatef(4,0,0);
                //drawCubeTexture();
                //Line
                fil.setpointf2(pointf2);
                fil.setpointf3(pointf3);
                fil.setpointf4(pointf4);
                fil.drawLine(pointf2,pointf3,pointf4);
            //glPopMatrix();//PP
            //glPushMatrix();//P
                //Boulet
                glTranslatef(1.5,0,0);
                boulet.drawBoulet();
            glPopMatrix();//PP
        glPopMatrix();//PP
    glPopMatrix();//PP

}
void Bras::setInclinaison(int inc){
    inclinaison=inc;
}
