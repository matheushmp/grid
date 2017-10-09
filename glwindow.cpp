#include "glwindow.h"
#include <stdio.h>

using namespace std;

glwindow::glwindow(QWidget *parent) :
    QGLWidget(parent)
{
     numW=30;
     numH=30;
    sizeX=1.0f;
    sizeY=1.0f;
    colorBp[0]=0.5f;
    colorBp[1]=0.5f;
    colorBp[2]=1.0f;
    colorGp[0]=0.5f;
    colorGp[1]=1.0f;
    colorGp[2]=0.5f;
    squares = new Square*[numW];
    for(int i=0 ; i<numW ; i++){
        squares[i] = new Square[numH];
    }
    blueP[0]=0; blueP[1]=0;
    greenP[0]=0; greenP[1]=numW-1;
    cont=0;
    desabilitar_mouse=0;
    for(int i=0 ; i<numW ; i++){
        for(int j=0 ; j<numH ; j++){
            float colorV[3]={0.6f,0.6f,0.6f};
            squares[i][j].setColor(colorV);
            squares[i][j].setSize(sizeX*1.0f, sizeY*1.0f);
            squares[i][j].setXY(i*sizeX*1.0f,j*sizeY*1.0f);
        }
    }
    float colorV[3]={0.0f,0.0f,1.0f};
    squares[0][0].setColor(colorBp);
    squares[numW-1][0].setColor(colorGp);
    colorChange(0,0);
    colorChange(numW-1,0);
}

void glwindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0 ; i<numW ; i++){
        for(int j=0 ; j<numH ; j++){
            squares[i][j].draw();
        }
    }

    if(lastex==0 && lastey==0){

    } else {
       //glClearColor(0.6 , 0.6 , 0.6 , 1.0);



        glColor3f(0.0 , 0.0 , 0.0);
        glBegin(GL_LINES);
        glVertex3f(lastex, lastey,1);
        glVertex3f(ex,ey,1);
        glEnd();
        glColor3f(1.0 , 1.0 , 1.0);
        glBegin(GL_LINES);
        glVertex3f(ex, ey,0);
        glVertex3f(eMovex,eMovey,0);
        glEnd();
         cout << ex << " " << ey << "\n" << lastex << " " << lastey << "\n";


    }

}

void glwindow::resizeGL(int w, int h)
{
    we=w;
    he=h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, numW*sizeX, 0, numH*sizeY, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void glwindow::initializeGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2 , 0.2 , 0.2 , 1.0);

}

void glwindow::mousePressEvent(QMouseEvent *e)                       // M�todo Acionado Com Evento Mouse Press (Clique)
{
    _mousex = e->x();                                         // Captura Posi��o X
    _mousey = e->y();                                         // Captura Posi��o Y
    ex =  numW*sizeX*_mousex/we;
    ey =  numH*sizeY -numH*sizeY*_mousey/he;
    int axisX=0;
    int axisY=0;
    for(int i=0 ; i<numW ; i++){
        for(int j=0 ; j<numH ; j++){
            if(ex-i*sizeX>0 && ex-(i+1)*sizeX<0 && ey-j*sizeY>0 && ey-(j+1)*sizeY<0){
                axisX=i;
                axisY=j;
            }else{
                float colorV[3]={0.6f,0.6f,0.6f};
                squares[i][j].setColor(colorV);
            }
        }
    }
    cout <<squares[axisX][axisY].getColor()[0]<< " "<<squares[axisX][axisY].getColor()[1]<< " "<<squares[axisX][axisY].getColor()[2]<< endl;

    colorChange(axisX,axisY);
    updateGL();

}

void glwindow::mouseMoveEvent(QMouseEvent *e)
{
//    _mouseMovex = e->x();                                         // Captura Posi��o X
//    _mouseMovey = e->y();                                         // Captura Posi��o Y
//    eMovex =  100*_mouseMovex/we;
//    eMovey =  100 -100*_mouseMovey/he;
//    updateGL();
}

void glwindow::mouseReleaseEvent(QMouseEvent *e)
{
//    lastex=ex;
//    lastey=ey;
//    _mousex = e->x();                                         // Captura Posi��o X
//    _mousey = e->y();                                         // Captura Posi��o Y
//    ex =  100*_mousex/we;
//    ey =  100 -100*_mousey/he;
    //    updateGL();
}

void glwindow::colorChange(int axisX, int axisY)
{
    if(squares[axisX][axisY].getColor()[0]==0.5 && squares[axisX][axisY].getColor()[1]==0.5 && squares[axisX][axisY].getColor()[2]==1){
        blueP[0]=axisX;
        blueP[1]=axisY;
    }
    float blue[3]={0.0f,0.0f,1.0f};
    squares[blueP[0]][blueP[1]].setColor(blue);
    if(blueP[0]-2>=0 && blueP[1]-1>=0){
        squares[blueP[0]-2][blueP[1]-1].setColor(colorBp);
    }
    if(blueP[0]-2>=0 && blueP[1]+1<numH){
        squares[blueP[0]-2][blueP[1]+1].setColor(colorBp);
    }
    if(blueP[0]-1>=0 && blueP[1]-2>=0){
        squares[blueP[0]-1][blueP[1]-2].setColor(colorBp);
    }
    if(blueP[0]-1>=0 && blueP[1]+2<numH){
        squares[blueP[0]-1][blueP[1]+2].setColor(colorBp);
    }
    if(blueP[0]+2<numW && blueP[1]-1>=0){
        squares[blueP[0]+2][blueP[1]-1].setColor(colorBp);
    }
    if(blueP[0]+2<numW && blueP[1]+1<numH){
        squares[blueP[0]+2][blueP[1]+1].setColor(colorBp);
    }
    if(blueP[0]+1<numW && blueP[1]-2>=0){
        squares[blueP[0]+1][blueP[1]-2].setColor(colorBp);
    }
    if(blueP[0]+1<numW && blueP[1]+2<numH){
        squares[blueP[0]+1][blueP[1]+2].setColor(colorBp);
    }
    if(squares[axisX][axisY].getColor()[0]==0.5 && squares[axisX][axisY].getColor()[1]==1 && squares[axisX][axisY].getColor()[2]==0.5){
        greenP[0]=axisX;
        greenP[1]=axisY;
    }
    float green[3]={0.0f,1.0f,0.0f};
    squares[greenP[0]][greenP[1]].setColor(green);
    for(int pos=1 ; greenP[0]-pos>=0 && greenP[1]-pos>=0 ; pos++){
        squares[greenP[0]-pos][greenP[1]-pos].setColor(colorGp);
    }
    for(int pos=1 ; greenP[0]-pos>=0 && greenP[1]+pos<numH ; pos++){
        squares[greenP[0]-pos][greenP[1]+pos].setColor(colorGp);
    }
    for(int pos=1 ; greenP[0]+pos<numW && greenP[1]-pos>=0 ; pos++){
        squares[greenP[0]+pos][greenP[1]-pos].setColor(colorGp);
    }
    for(int pos=1 ; greenP[0]+pos<numW && greenP[1]+pos<numH ; pos++){
        squares[greenP[0]+pos][greenP[1]+pos].setColor(colorGp);
    }
}



