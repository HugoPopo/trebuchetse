// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>
#include <QDebug>
#include <QGLWidget>
#include <QOpenGLTexture>
#include <GL/glu.h>
#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    setFocusPolicy(Qt::StrongFocus);
    xTra = 0;
    yTra = 0;
    zTra = -10;

    xRot = -50*16;

    yRot = 0;
    zRot = 90*16;
    zoom = 0.008;
    //Init
    setAngleBras(45);
    angleTreb = 45;
    //
    point2 = 0;
    point3 = 0;
    point4 = 0;
}

MyGLWidget::~MyGLWidget()
{

}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360*16;
    while (angle > (360*16))
        angle -= 360*16;
}

void MyGLWidget::setXRotation(int angle)
{

    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setXTranslation(float dist)
{
    xTra = xTra + dist;

    emit xTranslationChanged(xTra);
    updateGL();
}

void MyGLWidget::setYTranslation(float dist)
{
    yTra = yTra + dist;
    emit yTranslationChanged(yTra);
    updateGL();
}

void MyGLWidget::setZTranslation(float dist)
{
    zTra = zTra + dist;
    qDebug()<<zTra;
    emit zTranslationChanged(zTra);
    updateGL();
}


void MyGLWidget::setZoom(int scale)
{
    qDebug()<<scale;
    zoom = float(scale)/1000;
    emit zoomChanged(scale);
    updateGL();
}


void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glClearColor( 0.05, 0.46, 0.72, 1);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    //static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //static GLfloat light2Position[4] = {0, 10, 0, 1.0};
    //static GLfloat light2Direction[4] = {0, 0, 0, 1.0};
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    //glLightfv(GL_LIGHT1, GL_POSITION, light2Position);
    //glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light2Direction);

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(xTra, yTra, zTra);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    glScalef(zoom,zoom,zoom);
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + dy*8);
        setYRotation(yRot + dx*8);
    } else if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + dy*8);
        setZRotation(zRot + dx*8);
    }

    lastPos = event->pos();
}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z){
        float zoomInt = zoom*1000;
        int scale = (int)zoomInt + 2;
        setZoom(scale);
    } else if(event->key() == Qt::Key_S){
        float zoomInt = zoom*1000;
        int scale = (int)zoomInt - 2;
        setZoom(scale);
    } else if(event->key() == Qt::Key_Q){
        setXTranslation(0.3);
    }else if(event->key() == Qt::Key_D){
        setXTranslation(-0.3);
    }else if(event->key() == Qt::Key_A){
        setYTranslation(0.3);
    }else if(event->key() == Qt::Key_E){
        setYTranslation(-0.3);
    }else if(event->key() == Qt::Key_O){
        setAngleBras(100);
    }

}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    int scroll = (event->angleDelta().y())/60;
    float zoomInt = zoom*1000;
    int scale = (int)zoomInt + scroll;
    setZoom(scale);
}
//Angle bras
void MyGLWidget::setAngleBras(int angle)
{

    angleBras = angle-20;
    emit angleBrasChanged(angle);
    qDebug() << "Angle : " << angleBras;

    updateGL();
}
//Angle trébuchet
void MyGLWidget::setAngleTreb(int angle)
{


    angleTreb = angle;
    emit angleTrebChanged(angle);

}

void MyGLWidget::setPoint(float pointf2, float pointf3, float pointf4)
{
        point2=pointf2;
        point3=pointf3;
        point4=pointf4;
        emit pointChanged(pointf2,pointf3,pointf4);
        updateGL();
    }
void MyGLWidget::setLevel(int level){
    levelTarg=level;
    targ.lvlTarget(level);
    emit changedLevel(level);
}

void MyGLWidget::draw()
{
    if(treb.getImpact())
    {
        calcDistance();

    }
    glColor3f(1,1,1);
    glPushMatrix();
        glTranslatef(-330,0,1);
        //glTranslatef(0,0,2);
        glScalef(4,4,4);
        glRotatef(100+angleTreb,0,0,1);
        treb.drawTrebuchet(angleBras,point2,point3,point4);
    glPopMatrix();
    glColor3f(1,1,1);
    glPushMatrix();
        terr.drawTerrain();
    glPopMatrix();
    glPushMatrix();
        targ.drawTarget();
    glPopMatrix();
    update();

}

void MyGLWidget::tirer()
{
    treb.tirer();
    qDebug()<<"feu !";
}

void MyGLWidget::calcDistance()
{

    double h = treb.getBoulet().getX();
    double xB = h / cos((angleBras*0,01745));
    double yB = h / sin((angleBras*0,01745));
    // distance balle-cible
    double impactDist = sqrt(pow(xB - targ.getXTarget(),2) + pow(yB - targ.getYTarget(),2));
    emit changedScore(impactDist);
    treb.setImpact(FALSE);
}
