#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"
#include "bras.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
class Trebuchet: public Cube
{
public:
    Trebuchet();
    void drawTrebuchet(int angle,float pointf2,float pointf3,float pointf4);
    Bras getBras() { return bras; };

private:
    Bras bras;
    void poutreOblique();
    void fulcrum();
    void poutreSol();

    int angleCatapulte;
    int angleBras;
    QImage textbois;

    float pointf2,pointf3,pointf4;//Point finaux des lignes 2 à 4
};

#endif // TREBUCHET_H
