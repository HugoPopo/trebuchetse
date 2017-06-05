#ifndef BRAS_H
#define BRAS_H
#include "cube.h"
#include "line.h"
#include "boulet.h"

//Classe bras qui permet de dessiner le bras du trébuchet

class Bras: public Cube
{
public:
    Bras();
    void drawBras(float pointf2,float pointf3,float pointf4);
    //La méthode drawbras prends comme argument les points "finaux" des segments
    //qui forment la corde.
    void setInclinaison(int inc);
    Boulet getBoulet() { return boulet; };
private:
    //Methode permettant de dessiner une poutre de bois
    void poutre();
    //Méthode permettant de dessiner le contrepoid
    void drawContrepoid();
    //Entier correspondant à l'inclinaison du bras
    int inclinaison;
    //Le bras est composé d'un fil
    Line fil;
    //D'un boulet
    Boulet boulet;
    double masseContrePoids;
    //Pour la texture du bras nous avons besoins d'une QImage
    QImage textbois;
    //Points segments fil
    float pointf2,pointf3, pointf4;
};

#endif // BRAS_H
