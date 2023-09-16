#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 501;
int world[maxi][maxi];//그림
bool visit[maxi][maxi];//방문 여부
int maxArea = 0;//최대 넓이
//4방탐색
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//max
inline int max(int a,int b){
    return a>b?a:b;
}

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>world[i][j];
    }
}
//bfs
int bfs(int stX,int stY){
    visit[stX][stY] = true;
    int area = 1;
    queue<pair<int,int>> q;
    q.push({stX,stY});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        //다음 지점
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;//방문 체크
            if(visit[nx][ny]) continue;//방문 여부
            if(world[nx][ny]==0) continue;//빈공간
            
            visit[nx][ny] = true;
            q.push({nx,ny});
            area++;
        }
    }
    maxArea = max(maxArea,area);//최대 넓이
    return 1;
}

//그림
void Draw(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j] && world[i][j]==1) cnt+=bfs(i,j);
        }
    }
    cout<<cnt<<"\n";
    cout<<maxArea;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();//입력
    Draw();//그림
    return 0;
}
