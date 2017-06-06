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
//La classe MyGLWidget est notre classe principale elle permet de dessiner les éléments
//de notre "jeu"
class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    //Permet d'initialiser certains paramètre lié a openGL ex:Texture
    void initializeGL();
    //Permet de dessiner sur le Widget
    void paintGL();
    //Permet de redimenssionner la fenètre
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    //Pour gerer les èvenements utilisateurs
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
    //Gestion Angle Bras
    void setAngleBras(int angle);
    //gestion angle du trébuchet
    void setAngleTreb(int angle);
    //Gestion de l'animation du fil
    void setPoint(float pointf2,float pointf3,float pointf4);
signals:
    // signaling rotation from mouse movement
    void xTranslationChanged(float dist);
    void yTranslationChanged(float dist);
    void zTranslationChanged(float dist);
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    void zoomChanged(int scale);
    //Gestion Angle Bras et position trébuchet
    void angleTrebChanged(int angle);
    void angleBrasChanged(int angle);
    //Gestion Ligne
    void pointChanged(float pointf2,float pointf3,float pointf4);
private:
    void draw();
    //Objet à dessiner
    Trebuchet treb;
    Target targ;
    Terrain terr;
    //Rotation de la caméra
    int xRot;
    int yRot;
    int zRot;
    //Translation de la caméra
    float xTra;
    float yTra;
    float zTra;

    //Données nécessaire pour le jeu

    void calcTraf();    //Fonction qui va nous permettre de calculer la trajectoire de la balle
    int level; //Niveau de difficulté (3 niveaux de difficulté, facile, moyen difficile)
    bool visibleImpact;
    float calcScore; //Fonction qui va nous permettre de calculer le score, calcule de la distance entre l'impact et la cible
    float impX; //Coordonnées de l'impact
    float impY;

    int angleBras;  // Angle du bras du trébuchet
    int puissance;  //Puissance de jeter de la balle
    int angleTreb; //Angle du trebuchet

    float zoom;

    QPoint lastPos;
    //Points liés à l'animation de la corde
    float point2,point3, point4;
};

#endif // MYGLWIDGET_H
