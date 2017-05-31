#include "logo.h"

Logo::Logo()
{
    texttse=QImage(":/texture/Image/logo.png");

}

void Logo::drawLogo(float x,float y,float z){
    QOpenGLTexture* text1 = new QOpenGLTexture(texttse);
    text1->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    text1->setMagnificationFilter(QOpenGLTexture::Linear);
    text1->bind();
    glPushMatrix();

      glTranslatef(x,y,z);
      glScalef(2,2,0.1);
      drawCubeTexture();

    glPopMatrix();
}
