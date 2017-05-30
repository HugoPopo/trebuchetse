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
}

void Line::drawLine(){

    glBegin(GL_LINE_STRIP);

      glVertex2f(-4.00, 0.00);
      glVertex2f(-3.00, 2.00);
      glVertex2f(-2.00, 0.00);
      glVertex2f(-1.00, 2.00);
      glVertex2f(0.0, 0.00);
      glVertex2f(1.00, 2.00);
      glVertex2f(2.00, 0.00);
      glVertex2f(3.00, 2.00);
      glVertex2f(4.00, 0.00);

    glEnd();
}
