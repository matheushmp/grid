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
    Piece p;
    int position[2]={0,numH-1};
    p.changePosition(position);
    pieces.insert(pieces.begin(),p);
    squares[numW-1][0].setColor(colorGp);
    colorChange(blueP);
    colorChange(greenP);
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
    int axis[2]={0,0};
    for(int i=0 ; i<numW ; i++){
        for(int j=0 ; j<numH ; j++){
            if(ex-i*sizeX>0 && ex-(i+1)*sizeX<0 && ey-j*sizeY>0 && ey-(j+1)*sizeY<0){
                axis[0]=i;
                axis[1]=j;
            }else{
                float colorV[3]={0.6f,0.6f,0.6f};
                squares[i][j].setColor(colorV);
            }
        }
    }
    colorChange(axis);
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

void glwindow::colorChange(int *axis)
{
    std::vector<std::pair<int,int>> moveList;
    moveList=pieces[0].checkMove(0,0,numW,numH);
    Piece piece = pieces[0];
    if(checkForMove(moveList,axis)){
        piece.changePosition(axis);
        pieces[0]=piece;
        moveList=pieces[0].checkMove(0,0,numW,numH);
    }
    float green[3]={0.0f,1.0f,0.0f};
    squares[piece.checkPosition()[0]][piece.checkPosition()[1]].setColor(green);
    for(int i=0 ; i<moveList.size() ; i++){
        pair<int,int> p = moveList[i];
        squares[p.first][p.second].setColor(colorGp);
    }
}

bool glwindow::checkForBlue(int *position, int *axis)
{
    if(position[0]-axis[0]==2 || axis[0]-position[0]==2){
        if(position[1]-axis[1]==1 || axis[1]-position[1]==1){
            return true;
        }
    }else if (position[0]-axis[0]==1 || axis[0]-position[0]==1){
        if(position[1]-axis[1]==2 || axis[1]-position[1]==2){
            return true;
        }
    }
    return false;
}

bool glwindow::checkForMove(vector<pair<int,int>> moveList, int *axis)
{
    for(int i=0 ; i<moveList.size() ; i++){
        if(moveList[i].first==axis[0] && moveList[i].second==axis[1]){
            return true;
        }
    }
    return false;
}



