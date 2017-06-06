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
    // lancer le projectile
    void tirer();

private:
    // Construction graphique du trebuchet
    Bras bras;
    void poutreOblique();
    void fulcrum();
    void poutreSol();

    // Angles de construction
    int angleCatapulte;
    int angleBras;

    /* état du boulet:
     * 0: immobile
     * 1: au sol
     * 2: en l'air, relié à la corde
     * 3: en l'air, relâché
     */
    int etat;
    // angle de la corde au-delà duquel
    // le boulet est lâché
    double angleDeLacher;
    // timer pour chronométrer le lancer
    QTimer* lancerTimer = new QTimer();

    // Texture de bois pour les poutres
    QImage textbois;

    //Point finaux des lignes 2 à 4
    float pointf2,pointf3,pointf4;

};

#endif // TREBUCHET_H
