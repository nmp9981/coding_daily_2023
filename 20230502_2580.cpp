#include <iostream>
#include <vector>
using namespace std;

const int maxi =9;
int blankSize;
int sudoku[maxi][maxi];
vector<pair<int,int>> blanks;//빈칸

//입력
void input(){
    for(int i=0;i<maxi;i++){
        for(int j=0;j<maxi;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0) blanks.push_back({i,j});
        }
    }
    blankSize = blanks.size();
}
//행
bool Row(int k,int c){
    for(int i=0;i<maxi;i++){
        if(sudoku[i][c]==k) return false;
    }
    return true;
}
//열
bool Col(int k,int r){
    for(int j=0;j<maxi;j++){
        if(sudoku[r][j]==k) return false;
    }
    return true;
}
//박스
bool Box(int k,int r,int c){
    int st_r = (r/3)*3;
    int st_c = (c/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[st_r+i][st_c+j]==k) return false;
        }
    }
    return true;
}
//출력
void output(){
    for(int i=0;i<maxi;i++){
        for(int j=0;j<maxi;j++)cout<<sudoku[i][j]<<" ";
        cout<<"\n";
    }
}
//풀이
void Solve(int cnt){
    if(cnt==blankSize){
        output();//출력
        exit(0);
    }
    for(int k=1;k<=9;k++){
        int r = blanks[cnt].first;
        int c = blanks[cnt].second;
        if(Row(k,c)&&Col(k,r)&&Box(k,r,c)){
            sudoku[r][c] = k;
            Solve(cnt+1);
            sudoku[r][c] = 0;
        }
    }
}
int main()
{
    input();//입력
    Solve(0);//풀이
    return 0;
}
