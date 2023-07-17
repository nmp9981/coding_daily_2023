#include <iostream>
#include<vector>
using namespace std;

int len = 0;
int row,col;
const int maxi = 1001;
int square[maxi][maxi];//최대 길이

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//max
inline int max(int x,int y){
    return x>y?x:y;
}
//초기화
void init(vector<vector<int>> board){
    row = board.size();
    col = board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==1){
                len = 1;
                square[i][j] = 1;
            }else square[i][j] = 0;
        }
    }
}
//넓이
int Area(vector<vector<int>> board){
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(board[i][j]==1){
                square[i][j] = min(square[i-1][j-1],min(square[i-1][j],square[i][j-1]))+1;
                len = max(len,square[i][j]);
            }
        }
    }
    return len*len;
}
int solution(vector<vector<int>> board)
{
    init(board);//초기화
    return Area(board);//넓이
}
