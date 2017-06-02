#ifndef TARGET_H
#define TARGET_H


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
};


#endif // TARGET_H
