#include <string>
#include <vector>
#include <queue>
using namespace std;

//위치 정보
struct Pos{
    int x,y,dist;    
};
const int maxi = 102;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//아이템 줍기
//4방 탐색
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//max
inline int max(int x,int y){
    return x>y?x:y;
}
//맵세팅
void SetMap(vector<vector<int>> rectangle){
    //채우기
    for(int i=0;i<rectangle.size();i++){
        int x1 = 2*rectangle[i][0];
        int y1 = 2*rectangle[i][1];
        int x2 = 2*rectangle[i][2];
        int y2 = 2*rectangle[i][3];
        
        //채우기
        for(int i=min(x1,x2);i<=max(x1,x2);i++){
            for(int j=min(y1,y2);j<=max(y1,y2);j++) world[i][j] = 1;
        }
    }
    //가운데 빼기
    for(int i=0;i<rectangle.size();i++){
        int x1 = 2*rectangle[i][0];
        int y1 = 2*rectangle[i][1];
        int x2 = 2*rectangle[i][2];
        int y2 = 2*rectangle[i][3];
        
        //가운데 빼기
        for(int i=min(x1,x2)+1;i<max(x1,x2);i++){
            for(int j=min(y1,y2)+1;j<max(y1,y2);j++) world[i][j] = 0;
        }
    }
}
//아이템 줍기
int GetItem(int startX,int startY, int endX,int endY){
    visit[startX][startY] = true;
    queue<Pos> q;
    q.push({startX,startY,0});
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        if(x==endX && y==endY) return dist/2;//도착
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=maxi || ny<0 || ny>=maxi) continue;//범위 초과
            if(visit[nx][ny]) continue;//이미 방문
            if(world[nx][ny]==0) continue;//길이 아님
            
            visit[nx][ny] = true;
            q.push({nx,ny,dist+1});
        }
    }
    return 0;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    SetMap(rectangle);//맵세팅
    return GetItem(2*characterX,2*characterY,2*itemX,2*itemY);//아이템 줍기
}
