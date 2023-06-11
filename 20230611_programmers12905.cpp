#include <iostream>
#include <vector>
using namespace std;

int col,row;
int len = 0;
const int maxi = 1001;
int dp[maxi][maxi];//넓이

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//min
inline int min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(vector<vector<int>> board){
    row = board.size();
    col = board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) {
            dp[i][j] = board[i][j];
            len = max(len,dp[i][j]);
        }
    }
}
//넓이
int Square(vector<vector<int>> board){
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(board[i][j]==1){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                len = max(len,dp[i][j]);
            }
        }
    }
    return len*len;
}
int solution(vector<vector<int>> board)
{
    init(board);//초기화
    return Square(board);//넓이
}
