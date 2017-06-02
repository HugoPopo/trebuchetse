#include "filet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
Filet::Filet()
{

}
void Filet::drawFilet(){
//Méthode permettant de dessiner le filet autour du terrain
    glPushMatrix();
            //Dessin du Premier Poteau
            glPushMatrix();

                glTranslatef(-350,-175,35);
                glScalef(2,2,40);
                drawCube(127.5,127.5,127.5);
            glPopMatrix();
            glPushMatrix();
                //Dessin filets

                glTranslatef(0,-175,0);
                glPushMatrix();
                    for(int i = 0; i < 20; i++){
                        glTranslatef(0,0,3);
                        glPushMatrix();
                            glScalef(348,0.3,0.3);
                            drawCube(178.5, 137.4, 104.55);
                        glPopMatrix();
                    }
                glPopMatrix();
            glPopMatrix();
            //Cordes Verticales
            glTranslatef(-347,-175,30);
            glPushMatrix();
                for(int i = 0; i < 99; i++){
                    glTranslatef(7,0,0);
                    glPushMatrix();
                        glScalef(0.3,0.3,30);
                        drawCube(178.5, 137.4, 104.55);
                    glPopMatrix();
                }
            glPopMatrix();
            //Dessin du Second Poteau
            glPushMatrix();

                glTranslatef(698,2,0);
                glScalef(2,2,40);
                drawCube(127.5,127.5,127.5);
            glPopMatrix();
     glPopMatrix();

}
