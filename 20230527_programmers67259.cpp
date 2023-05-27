#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
    int x,y,dir;
};
const int maxi = 25;
const int inf = 100000000;
int cost[maxi][maxi][4];
//동남서북
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//초기화
void init(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++) cost[i][j][k] = inf;
        }
    }
}
//길 제작
int MakeRoad(int n,vector<vector<int>> board){
    int total = inf;
    queue<Pos> q;
    q.push({0,0,0});
    q.push({0,0,1});
    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();
        
        //도착점
        if(x==n-1 && y==n-1){
            total = min(total,cost[x][y][dir]);
        }
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;//범위 조건
            if(board[nx][ny]==1) continue;//벽
            
            if((dir+i)%2==1){//커브
                //더 작은 경우만
                if(cost[nx][ny][i] > cost[x][y][dir]+600){
                    cost[nx][ny][i] = cost[x][y][dir]+600;
                    q.push({nx,ny,i});   
                }
            }else{//직선
                //더 작은 경우만
                if(cost[nx][ny][i] > cost[x][y][dir]+100){
                    cost[nx][ny][i] = cost[x][y][dir]+100;
                    q.push({nx,ny,i});   
                }
            }
        }
    }
    return total;
}
int solution(vector<vector<int>> board) {
    int boardSize = board.size();
    init(boardSize);//초기화
    return MakeRoad(boardSize,board);//길 만들기
}
