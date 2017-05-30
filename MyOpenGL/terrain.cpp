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

}

//Fonction permettant de dessiner le terrain
void Terrain::drawTerrain()
{
    glPushMatrix();

      glTranslatef(0,0,10);
      glScalef(100,100,10);
      drawCube(40.8, 89.25, 0.0);

    glPopMatrix();

}
