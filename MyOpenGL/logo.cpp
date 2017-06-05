#include "logo.h"

Logo::Logo()
{
    texttse=QImage(":/texture/Image/logoTSE2.bmp");

}

void Logo::drawLogo(float x,float y,float z){
    QOpenGLTexture* text1 = new QOpenGLTexture(texttse);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();
    glPushMatrix();

      glTranslatef(x,y,z);
      glRotatef(90,0,0,1);
      glScalef(10,5,0.1);
      drawCubeTexture();

    glPopMatrix();
}
