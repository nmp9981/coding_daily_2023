#include <iostream>
#include <queue>
using namespace std;

int m,n;
const int maxi = 1001;
int board[maxi][maxi];//토마토 상태
int day[maxi][maxi];//날짜
//4방 탐색
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//입력
void input(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>board[i][j];
            day[i][j] = -1;
        }
    }
}
//토마토
int Tomato(){
    //처음지역 모두 큐에 담기
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                q.push({i,j});
                day[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;//방문 조건
            if(day[nx][ny]!=-1) continue;//방문 조건
            if(board[nx][ny]!=0) continue;//장애물
            
            day[nx][ny] = day[x][y]+1;
            board[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    //결과
    int maxDay= 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(board[i][j]!=-1 && day[i][j]==-1) return -1;
            maxDay = max(maxDay,day[i][j]);
        }
    }
    return maxDay;
}

int main()
{
    input();//입력
    cout<<Tomato();//토마토
    return 0;
}
