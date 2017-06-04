#ifndef FILET_H
#define FILET_H
#include "cube.h"

class Filet: public Cube
{
public:
    Filet();
    void drawFilet();
    void drawFiletDroit();
    void drawFiletGauche();
    void drawFiletFond();
};

#endif // FILET_H
