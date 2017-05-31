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
    texttse=QImage(":/texture/Image/logo.png");
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
      glScalef(100,100,10);
      drawCubeTexture();

    glPopMatrix();
    QOpenGLTexture* text2 = new QOpenGLTexture(texttse);
    text2->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text2->setMagnificationFilter(QOpenGLTexture::Linear);
    text2->bind();
    glPushMatrix();

      glTranslatef(20,20,0.5);
      glScalef(2,2,0.1);
      drawCubeTexture();

    glPopMatrix();


}
