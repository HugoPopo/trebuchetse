// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include "myglwidget.h"
#include "trebuchet.h"
#include "target.h"
#include "terrain.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *);
    void wheelEvent(QWheelEvent *event);


public slots:
    // slots for xyz-rotation slider
    void setXTranslation(float dist);
    void setYTranslation(float dist);
    void setZTranslation(float dist);

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setZoom(int scale);

signals:
    // signaling rotation from mouse movement
    void xTranslationChanged(float dist);
    void yTranslationChanged(float dist);
    void zTranslationChanged(float dist);
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void zoomChanged(int scale);


private:
    void draw();
    //Objet à dessiner
    Trebuchet treb;
    Target targ;
    Terrain terr;
    //
    int xRot;
    int yRot;
    int zRot;
    //Données nécessaire pour le jeu

    void calcTraf();    //Fonction qui va nous permettre de calculer la trajectoire de la balle
    void genTarget(); //Génération d'une cible en fonction de la difficulté
    int level; //Niveau de difficulté (3 niveaux de difficulté, facile, moyen difficile)
    bool visibleImpact;
    float calcScore; //Fonction qui va nous permettre de calculer le score, calcule de la distance entre l'impact et la cible
    float impX; //Coordonnées de l'impact
    float impY;
    float angleCorde;
    int angleBras;  // Angle du bras de la catapulte
    int puissance;  //Puissance de jeter de la balle


    float xTra;
    float yTra;
    float zTra;

    float zoom;

    QPoint lastPos;
};

#endif // MYGLWIDGET_H
