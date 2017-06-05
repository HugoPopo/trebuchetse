#ifndef LOGO_H
#define LOGO_H

#include "cube.h"
#include <QOpenGLTexture>
#include <QtOpenGL>

//La classe Logo permet de dessiner des logos de TSE
class Logo:public Cube
{
public:
    Logo();
    //Méthode qui permet de dessiner un logo en choisissant ça position
    //( les paramètre de cette méthode)
    void drawLogo(float x,float y ,float z);
private:
    //Image pour la texture des logos
    QImage texttse;
};

#endif // LOGO_H
