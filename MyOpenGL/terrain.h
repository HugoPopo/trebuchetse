#ifndef TERRAIN_H
#define TERRAIN_H
#include "cube.h"
#include <QOpenGLTexture>
#include <QtOpenGL>
#include "logo.h"
#include "filet.h"

class Terrain: public Cube
{
public:
    Terrain();

    void drawTerrain();
private:
    QImage textherbe;
    Logo logtse;
    Filet fil;
};

#endif // TERRAIN_H
