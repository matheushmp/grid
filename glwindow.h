#ifndef GLWINDOW_H
#define GLWINDOW_H
#include <QGLWidget>
#include <QMouseEvent>
#include <iostream>

class glwindow : public QGLWidget
{
     Q_OBJECT
public:
    explicit glwindow(QWidget *parent = 0);
    float _mousex;
    float _mousey;
    float ex=0;
    float ey=0;
    int cont;
    bool desabilitar_mouse;
    int we,he;
    float lastex=0;
    float lastey=0;



private:
    glwindow();
    void initializeGL();
    void resizeGL( int w, int h );
    void paintGL();


    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);





public slots:

};

#endif // GLWINDOW_H
