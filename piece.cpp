#include "piece.h"
using namespace std;
vector<pair<int,int>> Piece::checkMove(int lbx, int lby, int hbx, int hby)
{
    vector<pair<int,int>> possibleMoves;
    possibleMoves.clear();
    possibleMoves.begin();
    int numMoves=0;
    for(int i=0 ; i<=moveSpeed ; i++){
        for(int j=0 ; j<=moveSpeed-i ; j++){
            if(position[0]-i>=lbx){
                if(position[1]-j>=lby){
                    pair<int,int> point(position[0]-i,position[1]-j);
                    possibleMoves.insert(possibleMoves.end(),point);
                    numMoves++;
                }
                if(position[1]+j+1<hby && j+1<=moveSpeed-i){
                    pair<int,int> point(position[0]-i,position[1]+j+1);
                    possibleMoves.insert(possibleMoves.end(),point);
                    numMoves++;
                }
            }
            if(position[0]+i+1<hbx && i+1<=moveSpeed){
                if(position[1]-j>=lbx && j<=moveSpeed-(i+1)){
                    pair<int,int> point(position[0]+i+1,position[1]-j);
                    possibleMoves.insert(possibleMoves.end(),point);
                    numMoves++;
                }
                if(position[1]+j+1<hbx && j+1<=moveSpeed-(i+1)){
                    pair<int,int> point(position[0]+i+1,position[1]+j+1);
                    possibleMoves.insert(possibleMoves.end(),point);
                    numMoves++;
                }
            }
        }
    }
    cout<< numMoves<< endl;
    return possibleMoves;
}

int *Piece::checkPosition()
{
    return position;
}

void Piece::changePosition(int *newPosition)
{
    this->position[0]=newPosition[0];
    this->position[1]=newPosition[1];
}

Piece::Piece()
{

}
