#include "trebuchet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include <QDebug>
#include "ui_window.h"
//Methode de la classe Trebuchet :
//Permettant de dessiner et de gérer le déplacement du trébuchet

Trebuchet::Trebuchet()
{
    angleCatapulte = 0;
    angleBras = 0;
    textbois=QImage(":/texture/Image/bois.jpg");
    pointf2 = 0;
    pointf3 = 0;
    pointf4 = 0;
    etat = 0;
    timeLancer = 0;
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
            drawCubeTexture();
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



void Trebuchet::drawTrebuchet(int angle,float pointf2,float pointf3,float pointf4)
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
    // Placement du bras
    bras.setInclinaison(angle+angleBras);
    if(etat==1 || etat==2){
        angleBras -= 5;
        qDebug()<<"angle: "<<angleBras+angle;
        if(angleBras <= -100){
            etat = 3;
            xLache = boulet.getX();
            zLache = boulet.getZ();
            qDebug()<<"etat 3";
            qDebug()<<"debut chrono";
        }
    }
    if(etat == 3){
        if(boulet.getZ()<=0)
        {
            impact = true;
            etat = 4;
        }
        else
        {
            timeLancer += 0.1;
            boulet.setX(  boulet.getX() - boulet.getVitesseInitiale() );
            double sinus = (boulet.getZ() - zLache)/sqrt( pow((boulet.getZ()- zLache),2) + pow((boulet.getX()-xLache),2));
            boulet.setZ( -(9.8/2 *timeLancer*timeLancer) + boulet.getVitesseInitiale() * sinus * timeLancer + zLache );
            qDebug()<<"time lancer: "<<timeLancer;
            boulet.drawBoulet();
            qDebug()<<"boulet: "<<boulet.getX()<<" "<<boulet.getY()<<" "<<boulet.getZ();
        }
    }
    bras.drawBras(pointf2,pointf3,pointf4);
glPopMatrix();

}

void Trebuchet::tirer()
{
    etat = 1;
    qDebug()<<"feu trebuchet";
}
