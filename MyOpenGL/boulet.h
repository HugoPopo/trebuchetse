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

    // constante gravitationnel
    static const double G = 9.81;
    // position initiale
    static const double X0 = 1;
    static const double Y0 = 1;
    static const double Z0 = 1;

private:
    QImage textrock;
    double x, y, z;
    double vitesseInitiale;
};

#endif // BOULET_H
