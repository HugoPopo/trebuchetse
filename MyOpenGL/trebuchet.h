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
    void drawTrebuchet();


private:
    Bras bras;
    void poutreOblique();
    void fulcrum();
    void poutreSol();
    int angleCatapulte;
    int angleBras;
    QImage textbois;
};

#endif // TREBUCHET_H
