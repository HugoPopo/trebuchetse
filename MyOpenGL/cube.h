#ifndef CUBE_H
#define CUBE_H

//La classe cube est l'une de nos classes de bases qui nous permet de dessiner
//Un cube avec texture et un cube sans texture

class Cube
{
public:
    Cube();
    //Méthode permettant de dessiner un cube et de lui donner un couleur via
    //les paramètre de cette dernière
    void drawCube(int R, int G,int B);
    //Méthode permettant de dessiner un cube et de lui donner une texture
    void drawCubeTexture();
};

#endif // CUBE_H
