#ifndef TREBUCHET_H
#define TREBUCHET_H
#include "cube.h"

class trebuchet: public cube
{
public:
    trebuchet();
    void drawTrebuchet();

private:
    void drawBase();
    void drawPied();
    void drawContrepoid();
    void drawBras();
    int angleCatapulte;
    int angleBras;
};

#endif // TREBUCHET_H
