// window.cpp

#include <QtWidgets>
#include "window.h"
#include "ui_window.h"
#include <QPixmap>
#include <QDebug>
#include "myglwidget.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
   //Camera
   cam=new VideoCapture(0);


   if(!cam->isOpened())  // check if we succeeded
   {
     qDebug()<<":/";
   }
    //Dimension de la camera
   int frameWidth=cam->get(CV_CAP_PROP_FRAME_WIDTH);
   int frameHeight=cam->get(CV_CAP_PROP_FRAME_HEIGHT);
   frameWidth=frameWidth/2;
   frameHeight=frameHeight/2;
   cam->set(CV_CAP_PROP_FRAME_WIDTH, frameWidth);
   cam->set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);

    templateRect= new Rect((frameWidth-templateWidth)/2,(frameHeight-templateHeight)/2, templateWidth,templateHeight);
     connect(ui->myGLWidget, SIGNAL(angleBrasChanged(int)), ui->sliderAngleBras, SLOT(setValue(int)));
    //connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    //connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    //connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
     connect(timer, SIGNAL(timeout()), this, SLOT(update()));

     timer->start(50);


     go =false;

}
void Window::update(){



        if (cam->read(image)) {   // Capture a frame

           flip(image,image,1);

           // Pb ici
           templateImage = Mat(image, *templateRect).clone();
           if(!go){
           rectangle(image, *templateRect, Scalar(0,0,255),2,8,0);
           }
           float newsize = (ui->myGLWidget->width())/5;
           cv::resize(image, image, Size(newsize, newsize), 0, 0, INTER_LINEAR);
           cvtColor(image,image,CV_BGR2RGB);
           QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
           ui->camFrame->setPixmap(QPixmap::fromImage(img));
          }
    }

Window::~Window()
{
    delete ui;
}
void Window::on_checkBox_clicked()
{
//Nothing Yet
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
