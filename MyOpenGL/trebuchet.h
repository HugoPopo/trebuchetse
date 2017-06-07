#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"
#include "bras.h"
#include "boulet.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
class Trebuchet: public Cube, QObject
{
public:
    Trebuchet();
    void drawTrebuchet(int angle,float pointf2,float pointf3,float pointf4);
    Bras getBras() { return bras; };
    Boulet getBoulet() { return boulet; };
    // lancer le projectile
    void tirer();

private:
    // Construction graphique du trebuchet
    Bras bras;
    Boulet boulet;
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
    QTimer *timerLancer;
    double timeLancer;
    // Position du boulet lorsque il est laché par le bras
    double xLache, zLache;

    // Texture de bois pour les poutres
    QImage textbois;

    //Point finaux des lignes 2 à 4
    float pointf2,pointf3,pointf4;

private slots:
    void updateTimeLancer();

};

#endif // TREBUCHET_H
