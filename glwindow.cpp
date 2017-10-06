#include "glwindow.h"
#include <stdio.h>

using namespace std;

glwindow::glwindow(QWidget *parent) :
    QGLWidget(parent)
{
        cont=0;
        desabilitar_mouse=0;
}

void glwindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(lastex==0 && lastey==0){
        lastex=ex;
        lastey=ey;
    } else {
       glClearColor(0.6 , 0.6 , 0.6 , 1.0);
        glColor3f(1.0 , 1.0 , 1.0);
        glBegin(GL_LINES);
        glVertex3f(lastex, lastey,0);
        glVertex3f(ex,ey,0);
        glEnd();
        lastex=ex;
        lastey=ey;
    }

}

void glwindow::resizeGL(int w, int h)
{
    we=w;
    he=h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100.0, 0, 100.0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void glwindow::initializeGL()
{
    glClearColor(0.6 , 0.6 , 0.6 , 1.0);

}

void glwindow::mousePressEvent(QMouseEvent *e)                       // M�todo Acionado Com Evento Mouse Press (Clique)
{

        _mousex = e->x();                                         // Captura Posi��o X
        _mousey = e->y();                                         // Captura Posi��o Y
        ex =  100*_mousex/we;
        ey =  100 -100*_mousey/he;
        updateGL();
        cont++;
}

void glwindow::mouseMoveEvent(QMouseEvent *e)
{

}

void glwindow::mouseReleaseEvent(QMouseEvent *e)
{
}



