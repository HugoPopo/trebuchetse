#ifndef TARGET_H
#define TARGET_H


class target
{
public:
    target();
    void drawTarget();
    void drawCube(int R,int G,int B);
private:
    int xTarget =10;

    int yTarget =10;
};


#endif // TARGET_H
