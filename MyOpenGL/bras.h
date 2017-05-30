#ifndef BRAS_H
#define BRAS_H
#include "cube.h"


class Bras: public Cube
{
public:
    Bras();
    void poutre();
    void drawBras();
private:
    float inclinaison=0;
};

#endif // BRAS_H
