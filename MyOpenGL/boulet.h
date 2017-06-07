#ifndef BOULET_H
#define BOULET_H
#include<QImage>

//Classe bras qui permet de dessiner le boulet du trébuchet

class Boulet
{
public:
    Boulet();
    //Méthode qui permet de dessiner le boulet
    void drawBoulet();
    //Getters
    double getX() { return x; };
    double getY() { return y; };
    double getZ() { return z; };
    double getVitesseInitiale() { return vitesseInitiale; };
    //Setters
    void setX(double xS) { x=xS; };
    void setY(double yS) { y=yS; };
    void setZ(double zS) { z=zS; };
    void setVitesseInitiale(double vitInit) { vitesseInitiale = vitInit; };

private:
    //Texture du boulet
    QImage textrock;
    //Coordonnées
    double x, y, z;
    //Vitesse
    double vitesseInitiale;
};

#endif // BOULET_H
