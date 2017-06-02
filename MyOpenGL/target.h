#ifndef TARGET_H
#define TARGET_H
#include <QGLWidget>
#include <QOpenGLTexture>

class Target
{
public:
    Target();
    void drawTarget();
    void drawCube(int R,int G,int B);
    void lvlTarget(int level);
    void setxTarget(int x);
    void setyTarget(int y);
private:
    int xTarget =0;
    int yTarget =0;
    QImage texttarget;
};


#endif // TARGET_H
