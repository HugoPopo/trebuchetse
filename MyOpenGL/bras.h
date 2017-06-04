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
    void setInclinaison(int inc);
private:
    void poutre();
    void drawContrepoid();
    int inclinaison;
    Line fil;
    Boulet boule;
    QImage textbois;
};

#endif // BRAS_H
