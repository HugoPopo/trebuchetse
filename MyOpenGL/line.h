#ifndef LINE_H
#define LINE_H
#include<QImage>

class Line
{
public:
    Line();
    void drawLine(float pointf2,float pointf3,float pointf4);
    QImage textline;
    //setters
    void setpointf2(float pf2){pointf2=pf2;};
    void setpointf3(float pf3){pointf3=pf3;};
    void setpointf4(float pf4){pointf4=pf4;};
    //getters
    float getpointf2(){return pointf2;};
    float getpointf3(){return pointf3;};
    float getpointf4(){return pointf4;};
private:
    float pointf2,pointf3,pointf4;//Point finaux des lignes 2 à 4
};

#endif // LINE_H
