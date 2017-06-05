#ifndef FILET_H
#define FILET_H
#include "cube.h"

//La classe Filet permet de dessiner le filet tout autour du terrain
class Filet: public Cube
{
public:
    Filet();
    //Methode qui permet de dessiner un filet de base
    void drawFilet();
    //Méthode qui permet de dessiner le filet à droite du terrain
    void drawFiletDroit();
    //Méthode qui permet de dessiner le filet à gauche du terrain
    void drawFiletGauche();
    //Méthode qui permet de dessiner le filet à fond du terrain
    void drawFiletFond();
};

#endif // FILET_H
