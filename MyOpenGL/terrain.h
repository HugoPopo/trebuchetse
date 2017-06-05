#ifndef TERRAIN_H
#define TERRAIN_H
#include "cube.h"
#include <QOpenGLTexture>
#include <QtOpenGL>
#include "logo.h"
#include "filet.h"
//La classe Target permet de dessiner le terrain de jeu
class Terrain: public Cube
{
public:
    Terrain();
    //Méthode qui dessine le terrain
    void drawTerrain();
private:
    //texture du terrain
    QImage textherbe;
    //On en profite pour dessiner les éléments que l'on considère comme élément du
    //terrain
    Logo logtse;
    Filet fil;
};

#endif // TERRAIN_H
