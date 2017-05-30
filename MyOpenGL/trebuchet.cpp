#include "trebuchet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>

//Methode de la classe Trebuchet :
//Permettant de dessiner et de gérer le déplacement du trébuchet

Trebuchet::Trebuchet()
{

    angleCatapulte = 0;
    angleBras = 0;
}




//Ok
void Trebuchet::drawBase()
{
    glPushMatrix();
        //Partie Droite
        glPushMatrix();
            glTranslatef(15,0,0);
            glScalef (30, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
        //Partie Centrale
        glPushMatrix();
            glTranslatef(15,7.5,0);
            glScalef (30, 5, 1);
            drawCube(204,102,0);
        glPopMatrix();
        //Partie Gauche
        glPushMatrix();
            glTranslatef(15,15,0);
            glScalef (30, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
        //Support Triangle droit
        glPushMatrix();//Bon
            glRotatef(130,0,1,0);
            glTranslatef(4,0,7.75);
            glScalef (10, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
        glPushMatrix();//Bon
            glRotatef(230,0,1,0);
            glTranslatef(-1,0,11.25);
            glScalef (10, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
        //SupportTriangleGauche
        glPushMatrix();//Bon
            glRotatef(130,0,1,0);
            glTranslatef(4,15,7.75);
            glScalef (10, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
        glPushMatrix();//Bon
            glRotatef(230,0,1,0);
            glTranslatef(-1,15,11.25);
            glScalef (10, 1, 1);
            drawCube(204,102,0);
        glPopMatrix();
    glPopMatrix();
}


void Trebuchet::drawTrebuchet()
{
drawBase();//Ok
drawBras();//Ok
drawContrepoid();
}


void Trebuchet::drawContrepoid()
{

    glPushMatrix();
            glTranslatef(-15,7.5,-12);
            glScalef (5,5,4);
            drawCube(204,102,0);
       glPopMatrix();
}

//Ok
void Trebuchet::drawBras()
{
    //Bras + Liant Triangle
    glPushMatrix();

        glTranslatef(35,7.5,-14);
        glScalef (45, 2, 2);
        drawCube(204,102,0);
    glPopMatrix();
    glPushMatrix();

        glTranslatef(-1,7.5,-14);
        glScalef (1, 7.5, 1);
        drawCube(204,102,0);
    glPopMatrix();
}


//TODO gerer le mouvement de la balle
void Trebuchet::drawBoulet()
{
    GLUquadric* sphere = gluNewQuadric();
    glColor3f(178,178,178);
    glPushMatrix();
    glTranslatef(80,7.5,-17);
    glScalef(4,4,4);
    gluSphere(sphere, 1, 32,32);
    glPopMatrix();
}
