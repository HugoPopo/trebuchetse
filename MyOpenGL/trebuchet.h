#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"
#include "bras.h"
class Trebuchet: public cube
{
public:
    Trebuchet();
    void drawTrebuchet();


private:
    Bras bras;
    void poutreOblique();
    void fulcrum();
    void payload();
    void poutreSol();
    int angleCatapulte;
    int angleBras;
};

#endif // TREBUCHET_H
