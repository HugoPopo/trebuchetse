// window.cpp
// La classe window nous permet d'afficher les differents widgets et permet aussi le suivit de la main via une calibration
//manuel, slots on_checkBox_clicked(), qui va appeller la fonction tracking qui reconnait la main et la suit.
#include <QtWidgets>
#include <QTime>
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
    // chrono
    timeManche = new QTime(0,0,0);
    timeTotal = new QTime(0,0,0);
    qDebug()<<"manche"<<timeManche->toString("hh:mm:ss");
    qDebug()<<"Total"<<timeTotal->toString("hh:mm:ss");
    timerChrono = new QTimer(this);
    connect(timerChrono, SIGNAL(timeout()), this, SLOT(updateTime()));
    timerChrono->start(1000);
    updateTime();


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
void Window::trackingRect(){

    if (cam->read(image)) // Nouvelle Image de la camera
    {
        Rect resultRect;
        // On retourne l'image
        flip(image,image,1);

        // Do the Matching between the frame and the templateImage
        matchTemplate( image, matchImage, resultImage, TM_CCORR_NORMED );

        // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
        // Save the location fo the matched rect
        resultRect=Rect(maxLoc.x,maxLoc.y,templateWidth,templateHeight);
        // Show the result
        Mat normResultImage;
        // Normalize values
        normalize(resultImage,normResultImage,1,0,NORM_MINMAX);
        // Return to RGB to plot the max in red
        cvtColor(normResultImage,normResultImage,CV_GRAY2RGB);
        // Draw a red square
        rectangle(normResultImage,Rect(maxLoc.x,maxLoc.y,3,3),Scalar( 0, 0, 1),2,8,0);
        // Draw green rectangle on the frame
        rectangle(image,resultRect,Scalar( 0, 255, 0),2,8,0);
        // Display the image

        float newsize = (ui->myGLWidget->width())/5;
        cv::resize(image, image, Size(newsize, newsize), 0, 0, INTER_LINEAR);
        cvtColor(image,image,CV_BGR2RGB);
        QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
        ui->camFrame->setPixmap(QPixmap::fromImage(img));

    }
}
void Window::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        go=true;
        // Create the matchTemplate image result
        // to store the matchTemplate result
        int result_cols =  image.cols - templateImage.cols + 1;
        int result_rows = image.rows - templateImage.rows + 1;
        resultImage.create( result_cols, result_rows, CV_32FC1 );
        //imshow("template img",templateImage);
        matchImage=templateImage;
        //On change l'affichage pour suivre la main avec un nouveau rectangle
        timer->stop();
        connect(timer, SIGNAL(timeout()), this, SLOT(trackingRect()));
        timer->start(50);
    }else{
        go=false;
        timer->stop();
        //reset();
    }
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void Window::updateTime()
{
    *timeManche = timeManche->addSecs(1);
    *timeTotal = timeTotal->addSecs(1);
    QString textManche = timeManche->toString("hh:mm:ss");
    QString textTotal = timeTotal->toString("hh:mm:ss");
    ui->chrono_label->setText(textManche);
    ui->total_label->setText(textTotal);
}
