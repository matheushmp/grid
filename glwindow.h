#ifndef GLWINDOW_H
#define GLWINDOW_H
#include <QGLWidget>
#include <QMouseEvent>
#include <iostream>
#include "square.h"

class glwindow : public QGLWidget
{
     Q_OBJECT
public:
    explicit glwindow(QWidget *parent = 0);
    float _mousex;
    float _mousey;
    float ex=0;
    float ey=0;
    float _mouseMovex;
    float _mouseMovey;
    float eMovex=0;
    float eMovey=0;
    int cont;
    bool desabilitar_mouse;
    int we,he;
    float lastex=0;
    float lastey=0;
    int numW;
    int numH;
    float sizeX;
    float sizeY;
    Square** squares = NULL;
    float colorBp[3];
    float colorGp[3];
    int blueP[2];
    int greenP[2];


private:
    glwindow();
    void initializeGL();
    void resizeGL( int w, int h );
    void paintGL();


    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void colorChange(int axisX, int axisY);





public slots:

};

#endif // GLWINDOW_H
