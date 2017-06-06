#include "terrain.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include "cube.h"
Terrain::Terrain()
{
    textherbe=QImage(":/texture/Image/herbes.jpg");
}

//Fonction permettant de dessiner le terrain
void Terrain::drawTerrain()
{
    QOpenGLTexture* text1 = new QOpenGLTexture(textherbe);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();
    glPushMatrix();

      glTranslatef(0,0,-10);
      glScalef(350,175,10);
      drawCubeTexture();

    glPopMatrix();
    logtse.drawLogo(-300,-20,0.5);
    logtse.drawLogo(-300,20,0.5);

    glPushMatrix();
    glScalef(3,3,1);
    logtse.drawLogo(10,-40,0.5);
    logtse.drawLogo(10,40,0.5);

    glPopMatrix();
    fil.drawFilet();
    delete text1;
}
