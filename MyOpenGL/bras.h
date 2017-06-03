#ifndef BRAS_H
#define BRAS_H
#include "cube.h"
#include "line.h"


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
    QImage textbois;
};

#endif // BRAS_H
