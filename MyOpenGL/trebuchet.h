#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"
#include "bras.h"

class Trebuchet: public Cube
{
public:
    Trebuchet();
    void drawTrebuchet();


private:
    Bras bras;
    void poutreOblique();
    void fulcrum();
    void poutreSol();
    int angleCatapulte;
    int angleBras;
};

#endif // TREBUCHET_H
