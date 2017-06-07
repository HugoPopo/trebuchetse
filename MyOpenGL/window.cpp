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
	//Camera
    cam=new VideoCapture(0);
    //Chargement des highscore
    loadHighScore();
    //Besoin d'avoir un .ini
    if(!cam->isOpened())  // On regarde si tout est ok avec la camera
    {
        qDebug()<<":/";
    }
	
	//On redimensione la caméra
    int frameWidth=cam->get(CV_CAP_PROP_FRAME_WIDTH);
    int frameHeight=cam->get(CV_CAP_PROP_FRAME_HEIGHT);
    frameWidth=frameWidth/4;
    frameHeight=frameHeight/4;
    cam->set(CV_CAP_PROP_FRAME_WIDTH, frameWidth);
    cam->set(CV_CAP_PROP_FRAME_HEIGHT, frameHeight);

    templateRect= new Rect((frameWidth-templateWidth)/2,-20+(frameHeight-templateHeight)/2, templateWidth,templateHeight);

    //FOCUS FENETRE
    setFocusPolicy(Qt::StrongFocus);
	
    // chrono
    timeManche = new QTime(0,0,0);
    timeTotal = new QTime(0,0,0);
    qDebug()<<"manche"<<timeManche->toString("hh:mm:ss");
    qDebug()<<"Total"<<timeTotal->toString("hh:mm:ss");
    timerChrono = new QTimer(this);
    connect(timerChrono, SIGNAL(timeout()), this, SLOT(updateTime()));
    timerChrono->start(1000);


    //Mise a jour de l'interface


	//Changement lié au trébuchet
    connect(this, SIGNAL(angleTrebChanged(int)),ui->myGLWidget, SLOT(setAngleTreb(int)));
    connect(this, SIGNAL(angleBrasChanged(int)),ui->myGLWidget, SLOT(setAngleBras(int)));
    //Pour la corde :'(
    connect(this, SIGNAL(pointChanged(float,float,float)),ui->myGLWidget, SLOT(setPoint(float,float,float)));
    //Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //Pour la cible
    connect(this, SIGNAL(levelChanged(int)),ui->myGLWidget, SLOT(setLevel(int)));
    timer->start(10);
    //Pour l'actualisation du score
    connect(ui->myGLWidget, SIGNAL(changedScore(int)),this, SLOT(setScore(int)));
    //Test Qsettings
    //Ceci permet sauvegarder un fichier ini
    /*
    config->setValue("ScoreFacile/Nom", ui->highscoreTable->item(0,0)->text());
    config->setValue("ScoreFacile/Score", ui->highscoreTable->item(1,0)->text());
    config->setValue("ScoreFacile/Temps", ui->highscoreTable->item(2,0)->text());

    config->setValue("ScoreMoyen/Nom", ui->highscoreTable->item(0,1)->text());
    config->setValue("ScoreMoyen/Score", ui->highscoreTable->item(1,1)->text());
    config->setValue("ScoreMoyen/Temps", ui->highscoreTable->item(1,1)->text());

    config->setValue("ScoreDifficile/Nom", ui->highscoreTable->item(0,2)->text());
    config->setValue("ScoreDifficile/Score", ui->highscoreTable->item(1,2)->text());
    config->setValue("ScoreDifficile/Temps", ui->highscoreTable->item(2,2)->text());

    config->sync();
    */
    //
    play =false;
    newGame();
    updateTime();
}

void Window::newGame()
{

    partieDialog part;
    part.setModal(true);
    part.exec();

        level=part.getDifficulty();

        emit levelChanged(level);
        //Changer le niveau ui->myGLWidget->newTarget();
        nomJoueur = part.getName();
        countTarget = 0;
        ui->labelScore->setText("0");
        switch(level){
        case 1: ui->labelLevel->setText("Facile");
        break;
         case 2: ui->labelLevel->setText("Moyen");
        break;
         case 3: ui->labelLevel->setText("Difficile");
        break;
        }
        //Ajoute le start du chrono
        //Si on a une fonction de relance a la fin de partie
        timeManche->setHMS(0,0,0,0);
        timeTotal->setHMS(0,0,0,0);
    }

void Window::finPartie(){
    if (countTarget==9)
    {
        tempsfin=timeTotal->toString();
        displayHighScore();
        saveHighScore();

    }else{
        //On continue
        //Relancer Le chrono cible
        countTarget++;
        timeManche->setHMS(0,0,0,0);
        emit levelChanged(level);
        QString nb= QString::number(10-countTarget);
        ui->labelCibleR->setText(nb);

    }
}
void Window::update(){


	//Si on n'est pas en jeu
    if(!play){
        if (cam->read(image)) {   // Capture a frame
		   // vertical flip of the image
           flip(image,image,1);
           
           templateImage = Mat(image, *templateRect).clone();
           rectangle(image, *templateRect, Scalar(0,0,255),2,8,0);
           cvtColor(image,image,CV_BGR2RGB);//On passe en RGB
           QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
           ui->camFrame->setPixmap(QPixmap::fromImage(img));
		   //On positionne l'image sur la frame associer a la camera 
         }
    } else {
        if (cam->read(image)) // Capture Frame
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

            //Changement Rotation du trébuchet suivi du bras :p
            angleTrebChanged(resultRect.x);
            angleBrasChanged(resultRect.y);
            //Le fil
            pointChanged(resultRect.x*0.01,resultRect.y*0.01,resultRect.x*0.01);
            if(impact==1){
                finPartie();
                impact=0;
                qDebug()<<"Test";
            }
        }
    }
}

Window::~Window()
{
    delete ui;
	delete cam;
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

        play=true;
    }
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        ui->checkBox->setChecked(true);
    }
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

void Window::loadHighScore(){

    //Facile
    ui->highscoreTable->setItem(0,0,new QTableWidgetItem(config->value("ScoreFacile/Nom").toString()));
    ui->highscoreTable->setItem(1,0,new QTableWidgetItem(config->value("ScoreFacile/Score").toString()));
    ui->highscoreTable->setItem(2,0,new QTableWidgetItem(config->value("ScoreFacile/Chrono").toString()));

    //Moyen
    ui->highscoreTable->setItem(0,1,new QTableWidgetItem(config->value("ScoreMoyen/Nom").toString()));
    ui->highscoreTable->setItem(1,1,new QTableWidgetItem(config->value("ScoreMoyen/Score").toString()));
    ui->highscoreTable->setItem(2,1,new QTableWidgetItem(config->value("ScoreMoyen/Chrono").toString()));

    //Difficile
    ui->highscoreTable->setItem(0,2,new QTableWidgetItem(config->value("ScoreDifficile/Nom").toString()));
    ui->highscoreTable->setItem(1,2,new QTableWidgetItem(config->value("ScoreDifficile/Score").toString()));
    ui->highscoreTable->setItem(2,2,new QTableWidgetItem(config->value("ScoreDifficile/Chrono").toString()));
}

void Window::saveHighScore(){
    //Facile
    config->setValue("ScoreFacile/Nom", ui->highscoreTable->item(0,0)->text());
    config->setValue("ScoreFacile/Score", ui->highscoreTable->item(1,0)->text());
    config->setValue("ScoreFacile/Temps", ui->highscoreTable->item(2,0)->text());
    //Moyen
    config->setValue("ScoreMoyen/Nom", ui->highscoreTable->item(0,1)->text());
    config->setValue("ScoreMoyen/Score", ui->highscoreTable->item(1,1)->text());
    config->setValue("ScoreMoyen/Temps", ui->highscoreTable->item(1,1)->text());
    //Difficile
    config->setValue("ScoreDifficile/Nom", ui->highscoreTable->item(0,2)->text());
    config->setValue("ScoreDifficile/Score", ui->highscoreTable->item(1,2)->text());
    config->setValue("ScoreDifficile/Temps", ui->highscoreTable->item(2,2)->text());
}

void Window::resetHighScore(){
    config->clear();
}

void Window::displayHighScore(){
    switch(level){
    case 1 :
    {
        int scoreF = ui->highscoreTable->item(1,0)->text().toInt();
        if (score>scoreF){
            ui->highscoreTable->setItem(0,0,new QTableWidgetItem(nomJoueur));
            ui->highscoreTable->setItem(1,0,new QTableWidgetItem(QString::number(score)));
            ui->highscoreTable->setItem(2,0,new QTableWidgetItem(timeTotal->toString()));
        }

     break;
    }
    case 2 :
    {
    int scoreI = ui->highscoreTable->item(1,1)->text().toInt();
    if (score>scoreI){
        ui->highscoreTable->setItem(0,1,new QTableWidgetItem(nomJoueur));
        ui->highscoreTable->setItem(1,1,new QTableWidgetItem(QString::number(score)));
        ui->highscoreTable->setItem(2,1,new QTableWidgetItem(timeTotal->toString()));
    }

    break;}
    case 3 :
    {
        int scoreD = ui->highscoreTable->item(1,2)->text().toInt();
        if (score>scoreD){
            ui->highscoreTable->setItem(0,2,new QTableWidgetItem(nomJoueur));
            ui->highscoreTable->setItem(1,2,new QTableWidgetItem(QString::number(score)));
            ui->highscoreTable->setItem(2,2,new QTableWidgetItem(timeTotal->toString()));
        }

    break;}
    default:
        break;
          }
    }
void Window::setScore(int scor){
    //Notre cible est formée de 10 anneaux est son rayon est de 50
    if(countTarget < 10){
        if(scor<5){
            score=score+10;
        }else if (scor<10){
            score=score+9;
        }else if (scor<15){
            score=score+8;
        }else if (scor<20){
            score=score+7;
        }else if (scor<25){
            score=score+6;
        }else if (scor<30){
            score=score+5;
        }else if (scor<35){
            score=score+4;
        }else if (scor<40){
            score=score+3;
        }else if (scor<45){
            score=score+2;
        }else if (scor<50){
            score=score+1;
        }else{
            score=score+0;
        }
        ui->labelScore->setText(QString::number(score));
        impact=1;
        //On actualise le score
    }
}
