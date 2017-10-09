#ifndef SQUARE_H
#define SQUARE_H

#include <QGLWidget>

class Square
{
private:
    float x;
    float y;
    float sizeX;
    float sizeY;
    float color[3]={0.2f , 0.2f , 0.2f};
public:
    Square();
    void draw();
    void setXY(float x , float y);
    void setSize(float sizeX , float sizeY);
    void setColor(float color[3]);
    float* getColor();

};

#endif // SQUARE_H
