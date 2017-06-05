#ifndef LINE_H
#define LINE_H
#include<QImage>

//La classe Line permet de dessiner le fil entre le bras et le boulet
class Line
{
public:
    Line();

    void drawLine(float pointf2,float pointf3,float pointf4);
    //La méthode drawline prends comme argument les points "finaux" des segments
    //qui forment la corde. Comme son nom l'indique elle permet de dessiner une ligne

    //setters
    void setpointf2(float pf2){pointf2=pf2;};
    void setpointf3(float pf3){pointf3=pf3;};
    void setpointf4(float pf4){pointf4=pf4;};
    //getters
    float getpointf2(){return pointf2;};
    float getpointf3(){return pointf3;};
    float getpointf4(){return pointf4;};
private:
    //Pour la texture de la ligne (obsolète)
    QImage textline;
    //Points segments fil
    float pointf2,pointf3,pointf4;
    //Point finaux des lignes 2 à 4
};

#endif // LINE_H
