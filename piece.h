#ifndef PIECE_H
#define PIECE_H

#include <QGLWidget>
#include <iostream>
#include <stdio.h>
#include<list>
class Piece
{
private:
    float color[3];
    int position[2];
    int moveSpeed=3;
public:
    void move(int mx, int my);
    std::vector<std::pair<int,int>> checkMove(int lbx, int lby, int hbx, int hby);
    int* checkPosition();
    void changePosition(int* newPosition);
    void drawP();
    Piece();
};

#endif // PIECE_H
