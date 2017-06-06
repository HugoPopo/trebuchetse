// window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "opencv2/opencv.hpp"

#include "opencv2/highgui.hpp"
#include<QLabel>
#include"partiedialog.h"
using namespace cv;

//La classe Window permet de definir notre fenetre principale, de mettre les
//chronomettre, de récuperer les informations sur l'utilisateurs(mouvement)

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    void newGame();
    //Méthode qui gere la création d'une nouvelle partie
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Window *ui;
    QTimer *timer = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    QTimer *timerChrono  = new QTimer(this);
    QTime *timeManche;
    QTime *timeTotal;
    //Reconnaissance main
    //Dimension du rectangle
    int templateWidth = 30;
    int templateHeight = 30;
    Rect *templateRect;
    //Camera
    VideoCapture * cam;
    //Pour la reconnaissance de main
    Mat templateImage;
    Mat matchImage;
    Mat resultImage;
    Mat image;
    //Pour gerer le jeu
    bool play;
    //play permet de définir le tracking ou non de la main
    bool bouletLancer;
    //Si le boulet est animer
    //Info partie
    int countTarget;
    //Nombre de cible joueur une partie en compte 10
    int level=1;
    //Le choix du niveau
    int score = 0;
    //Le score
    QString nomJoueur;
    //Le nom du joueur pour les highscores
    int i;
    //animation corde
    float pointf2,pointf3, pointf4;
private slots:
    void update();
    void on_checkBox_clicked();

    void updateTime();


signals:

    //Gestion Angle Bras et position trébuchet
    void angleTrebChanged(int angleTreb);
    void angleBrasChanged(int angle);
    //Gestion Ligne
    void pointChanged(float pointf2,float pointf3,float pointf4);
    //Fermer le dialog
    void closeDialog();
};

#endif // WINDOW_H
