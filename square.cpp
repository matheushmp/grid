#include "square.h"

Square::Square()
{

}

void Square::setXY(float x, float y)
{
    this->x=x;
    this->y=y;
}

void Square::setSize(float sizeX, float sizeY)
{
    this->sizeX=sizeX;
    this->sizeY=sizeY;
}

void Square::setColor(float color[])
{
    for(int i=0 ; i<3 ; i++){
        this->color[i]=color[i];
    }
}

float *Square::getColor()
{
    return this->color;
}

void Square::draw()
{
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_TRIANGLES);
    glVertex3f(x+0.05f,y+0.05f,-1);
    glVertex3f(x+sizeX-0.05f,y+0.05f,-1);
    glVertex3f(x+0.05f,y+sizeY-0.05f,-1);

    glVertex3f(x+sizeX-0.05f,y+0.05f,-1);
    glVertex3f(x+0.05f,y+sizeY-0.05f,-1);
    glVertex3f(x+sizeX-0.05f,y+sizeY-0.05f,-1);
    glEnd();

}
