#include "line.h"
#include "bras.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>

Line::Line()
{
textline=QImage("Image/bois.jpg");
pointf2 = 0;
pointf3 = 0;
pointf4 = 0;
}

void Line::drawLine(float pointf2,float pointf3,float pointf4){

    glBegin(GL_LINE_STRIP);

      glVertex2f(-4.00, 0.00);//Première Ligne
      glVertex2f(-3.00, pointf2);//Seconde
      glVertex2f(-2.00, pointf3);//Third
      glVertex2f(-1.00, pointf4);//Fourth
      glVertex2f(0.0, 0.00);
      //On change les points d'arriver pour l'animation




    glEnd();
}
