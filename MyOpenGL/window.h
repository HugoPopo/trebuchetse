// window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "opencv2/opencv.hpp"

#include "opencv2/highgui.hpp"
#include<QLabel>
#include<QSettings>
#include<QDir>
#include"partiedialog.h"
using namespace cv;

//La classe Window permet de definir notre fenetre principale, de mettre les
//chronomettre, de récuperer les informations sur l'utilisateurs(mouvement)
//de calculer le score des joueurs et d'enregistrer un fichier .ini afin de stocker les
//meilleurs scores
namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

    //Méthode qui gere la création d'une nouvelle partie
    void newGame();

    //Calcule du score en fin de partie
    void finPartie();
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
    //Le nom du joueur pour les highscores
    QString nomJoueur;

    //animation corde
    float pointf2,pointf3, pointf4;
    //Temps en fin de partie pour highsc
    QString tempsfin;

    //Gestion du tableau des scores
    QSettings *config= new QSettings(QDir::currentPath() +"/config.ini",QSettings::IniFormat);
    //Format de config.ini (copier coller dans le build pour avoir un tableau des scores pré-remplie
    /*
    [ScoreFacile]
    Nom=Bertrand
    Score=0
    Temps=

    [ScoreMoyen]
    Nom=Panda Roux
    Score=444
    Temps=0

    [ScoreDifficile]
    Nom=Moulin
    Score=0
    Temps=0
    */

    //Différente methode qui permettent l'affichage des scores
    void resetHighScore();
    void saveHighScore();
    void loadHighScore();
    void displayHighScore();
    //Valeur pour fin de partie
    int impact=0;
private slots:
    //Actualisation de la fenetre
    void update();
    //Pour la calibration de la main
    void on_checkBox_clicked();
    //Permet d'actualiser les chronos
    void updateTime();
    //Methode permettant de calculer le score
    void setScore(int scor);

signals:

    //Gestion Angle Bras et position trébuchet
    void angleTrebChanged(int angleTreb);
    void angleBrasChanged(int angle);
    //Gestion Ligne
    void pointChanged(float pointf2,float pointf3,float pointf4);
    //Fermer le dialog
    void closeDialog();
    //Changement de niveau
    void levelChanged(int level);
};

#endif // WINDOW_H
