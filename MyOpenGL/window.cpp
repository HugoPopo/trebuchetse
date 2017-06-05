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
    frameWidth=frameWidth/6;
    frameHeight=frameHeight/6;
    cam->set(CV_CAP_PROP_FRAME_WIDTH, frameWidth);
    cam->set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);

    templateRect= new Rect((frameWidth-templateWidth)/2,(frameHeight-templateHeight)/2, templateWidth,templateHeight);
    //Changement lié au trébuchet
    connect(this, SIGNAL(posYChanged(int)),ui->myGLWidget, SLOT(setposY(int)));
    connect(this, SIGNAL(angleBrasChanged(int)),ui->myGLWidget, SLOT(setAngleBras(int)));
    //Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(50);


    go =false;

}
void Window::update(){



    if(!go){
        if (cam->read(image)) {   // Capture a frame
           flip(image,image,1);
           templateImage = Mat(image, *templateRect).clone();
           rectangle(image, *templateRect, Scalar(0,0,255),2,8,0);
           //float newsize = (ui->centralWidget->width())/5;
           //cv::resize(image, image, Size(newsize, newsize), 0, 0, INTER_LINEAR);
           cvtColor(image,image,CV_BGR2RGB);
           QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
           ui->camFrame->setPixmap(QPixmap::fromImage(img));
         }
    } else {
        if (cam->read(image)) // get a new frame from camera
        {
            Rect resultRect;
            double minVal; double maxVal; Point minLoc; Point maxLoc;
            maxVal=0.20;
            // vertical flip of the image
            flip(image,image,1);
            // Do the Matching between the frame and the templateImage
            matchTemplate(image, matchImage, resultImage, TM_CCORR_NORMED);
            // Localize the best match with minMaxLoc
            minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
            // Save the location fo the matched rect
            resultRect=Rect(maxLoc.x,maxLoc.y,templateWidth,templateHeight);
            rectangle(image,resultRect,Scalar( 0, 255, 0),2,8,0);
            // Display the image
             cvtColor(image,image,CV_BGR2RGB);
            QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
            ui->camFrame->setPixmap(QPixmap::fromImage(img));
            qDebug()<<resultRect.x;
            posYChanged(resultRect.x);

        }
    }
}

Window::~Window()
{
    delete ui;
}

void Window::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        // Create the matchTemplate image result
        // to store the matchTemplate result
        int result_cols =  image.cols - templateImage.cols + 1;
        int result_rows = image.rows - templateImage.rows + 1;
        resultImage.create( result_cols, result_rows, CV_32FC1 );
        matchImage=templateImage;

        go=true;
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
