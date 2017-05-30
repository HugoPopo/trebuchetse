#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"

class Trebuchet: public cube
{
public:
    Trebuchet();
    void drawTrebuchet();
    void drawBoulet();

private:
    void drawBase();
    void drawPied();
    void drawContrepoid();
    void drawBras();
    int angleCatapulte;
    int angleBras;
};

#endif // TREBUCHET_H
