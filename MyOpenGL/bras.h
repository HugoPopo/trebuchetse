#ifndef BRAS_H
#define BRAS_H
#include "cube.h"
#include "line.h"
#include "boulet.h"

class Bras: public Cube
{
public:
    Bras();
    void drawBras();
    void setInclinaison(float inc);
private:
    void poutre();
    void drawContrepoid();
    float inclinaison=10;
    Line fil;
    Boulet boule;
    QImage textbois;
};

#endif // BRAS_H
