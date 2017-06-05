#ifndef BRAS_H
#define BRAS_H
#include "cube.h"
#include "line.h"
#include "boulet.h"

class Bras: public Cube
{
public:
    Bras();
    void drawBras(float pointf2,float pointf3,float pointf4);
    void setInclinaison(int inc);
    Boulet getBoulet() { return boulet; };
private:
    void poutre();
    void drawContrepoid();
    int inclinaison;
    Line fil;
    Boulet boulet;
    double masseContrePoids;
    QImage textbois;
    float pointf2,pointf3, pointf4;
};

#endif // BRAS_H
