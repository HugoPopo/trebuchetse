#ifndef LOGO_H
#define LOGO_H

#include "cube.h"
#include <QOpenGLTexture>
#include <QtOpenGL>
class Logo:public Cube
{
public:
    Logo();
    void drawLogo(float x,float y ,float z);
private:
    QImage texttse;
};

#endif // LOGO_H
