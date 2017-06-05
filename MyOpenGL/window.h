// window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "opencv2/opencv.hpp"

#include "opencv2/highgui.hpp"
#include<QLabel>
using namespace cv;

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

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
    VideoCapture * cam;
    Mat templateImage;
    Mat matchImage;
    Mat resultImage;
    Mat image;
    bool go;
    int angle=0;
    int posY=0;
private slots:
    void update();
    void on_checkBox_clicked();

    void updateTime();

signals:

    //Gestion Angle Bras et position trébuchet
    void posYChanged(int angleCatapulte);
    void angleBrasChanged(int angle);
};

#endif // WINDOW_H
