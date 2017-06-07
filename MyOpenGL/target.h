#ifndef TARGET_H
#define TARGET_H
#include <QGLWidget>
#include <QOpenGLTexture>
//La classe Target permet de dessiner une cible sur le terrain de jeu
class Target
{
public:
    Target();
    //Permet de dessiner une cible au centre du terrain
    void drawTarget();
    //Permet de dessiner un cible aléatoirement en fonction du niveau choisis
    void lvlTarget(int level);
    //Setters
    void setxTarget(int x);
    void setyTarget(int y);
    int getXTarget(){ return xTarget; };
    int getYTarget(){ return yTarget; };

private:
    //Coordonnées de la cible
    int xTarget =0;
    int yTarget =0;
    //texture de la cible
    QImage texttarget;
};


#endif // TARGET_H
