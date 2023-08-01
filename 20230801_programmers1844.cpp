#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
const int maxi = 101;
int visit[maxi][maxi];//방문 여부

int Adventure(vector<vector<int>> maps){
    n = maps.size();
    m = maps[0].size();
    
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x==n-1 && y==m-1) return visit[x][y];//도착
        
        //4방 탐색
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;//범위 조건
            if(maps[nx][ny]==0) continue;//장애물
            if(visit[nx][ny]!=-1) continue;//이미 방문
            
            visit[nx][ny] = visit[x][y]+1;
            q.push({nx,ny});
        }
    }
    return -1;//도달 불가
}
int solution(vector<vector<int> > maps)
{
    memset(visit,-1,sizeof(visit));//초기화
    return Adventure(maps);
}
