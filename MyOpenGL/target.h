#ifndef TARGET_H
#define TARGET_H


class Target
{
public:
    Target();
    void drawTarget();
    void drawCube(int R,int G,int B);
private:
    int xTarget =10;
    int yTarget =10;
};


#endif // TARGET_H
