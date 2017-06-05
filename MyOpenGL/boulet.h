#ifndef BOULET_H
#define BOULET_H
#include<QImage>

class Boulet
{
public:
    Boulet();
    void drawBoulet();
    double getX() { return x; };
    double getY() { return y; };
    double getZ() { return z; };

private:
    QImage textrock;
    double x, y, z;
    double vitesseInitiale;
};

#endif // BOULET_H
