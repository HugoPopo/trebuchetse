#include "boulet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
Boulet::Boulet()
{

}


//TODO gerer le mouvement de la balle
void Boulet::drawBoulet()
{
    GLUquadric* sphere = gluNewQuadric();
    glColor3f(178,178,178);
    glPushMatrix();
    glTranslatef(80,7.5,-17);
    glScalef(4,4,4);
    gluSphere(sphere, 1, 32,32);
    glPopMatrix();
}
