#include "trebuchet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include <QDebug>
//Methode de la classe Trebuchet :
//Permettant de dessiner et de gérer le déplacement du trébuchet

Trebuchet::Trebuchet()
{

    angleCatapulte = 0;
    angleBras = 0;
    textbois=QImage(":/texture/Image/bois.jpg");
}



//Ok
void Trebuchet::poutreSol()
{
        QOpenGLTexture* text1 = new QOpenGLTexture(textbois);
        text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
        text1->setMagnificationFilter(QOpenGLTexture::Linear);
        text1->bind();
        //Partie Droite
        glPushMatrix();
            glTranslatef(0, 0, 0.125);
            glScalef (3,0.125, 0.125);
            ;
        glPopMatrix();
}




void Trebuchet::poutreOblique()
{
    /*color .34 .16 0
translate 0 0 .75
rotate 45 0 1 0
scale 2 .125 .125*/
    QOpenGLTexture* text1 = new QOpenGLTexture(textbois);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();

    glPushMatrix();
            glTranslatef(0,0,1.5);
            glRotatef(45,0,1,0);
            glScalef (2,0.125,0.125);
            drawCubeTexture();
     glPopMatrix();
}

//Ok
void Trebuchet::fulcrum()
{
    /*
 color .45 .4 .45
rotate 90 1 0 0
scale .15 .15 .5
     */
    GLUquadric* sphere = gluNewQuadric();
    glColor3f(0.45,0.4,0.45);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(0.15,0.15,0.5);
    gluSphere(sphere, 1, 32,32);
    glPopMatrix();
}



void Trebuchet::drawTrebuchet(int angle)
{
//Poutre Sol
glPushMatrix();
    //
    glTranslatef(1.25,0,0);
    poutreSol();
    //
    glTranslatef(0,0.5,0);
    poutreSol();
    //
    glRotatef(90,0,0,1);
    glScalef(0.75,1,1);
    glTranslatef(1.5,0,0);
    poutreSol();
    //
    glTranslatef(-3.75,0,0);
    poutreSol();
    //
glPopMatrix();

//Placement Poutre oblique
glPushMatrix();
    glTranslatef(2.5,0,0);
    poutreOblique();
    //
    glTranslatef(0,0.5,0);
    poutreOblique();
    //
    glRotatef(90,0,0,1);
    glTranslatef(1.5,1.25,0);
    poutreOblique();
    //
    glRotatef(90,0,0,1);
    glTranslatef(1.5,1.5,0);
    poutreOblique();
    //
    glTranslatef(0,0.5,0);
    poutreOblique();
    //
    glRotatef(90,0,0,1);
    glTranslatef(1.5,1.5,0);
    poutreOblique();
glPopMatrix();


//Fulcrum
glPushMatrix();
    glTranslatef(1.25,0.25,2.75);
    fulcrum();
glPopMatrix();
bras.setInclinaison(angle);

bras.drawBras();

}
