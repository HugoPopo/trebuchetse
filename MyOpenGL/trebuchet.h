#ifndef TREBUCHET_H
#define TREBUCHET_H


class trebuchet
{
public:
    trebuchet();
    void drawTrebuchet();

private:

    void drawCube(int R, int G,int B);

    void drawBase();
    void drawPied();
    void drawContrepoid();
    void drawBras();
    int angleCatapulte;
    int angleBras;
};

#endif // TREBUCHET_H
