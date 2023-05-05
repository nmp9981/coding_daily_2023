#include <string>
#include <vector>
#include <queue>
using namespace std;

//위치 정보
struct Pos{
    int r,c,dist;
};

const int maxi = 102;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

//맵 세팅
void WorldSetting(vector<vector<int>> rectangle){
    //칸 채우기
    for(int i=0;i<rectangle.size();i++){
        int startX = 2*rectangle[i][0];
        int startY = 2*rectangle[i][1];
        int endX = 2*rectangle[i][2];
        int endY = 2*rectangle[i][3];
        
        for(int i=startY;i<=endY;i++){
            for(int j=startX;j<=endX;j++) world[i][j] = 1;
        }
    }
    //가운데 빼기
    for(int i=0;i<rectangle.size();i++){
        int startX = 2*rectangle[i][0];
        int startY = 2*rectangle[i][1];
        int endX = 2*rectangle[i][2];
        int endY = 2*rectangle[i][3];
        
        for(int i=startY+1;i<endY;i++){
            for(int j=startX+1;j<endX;j++) world[i][j] = 0;
        }
    }
}
//아이템 먹기
int GetItem(int chaX,int chaY,int temX,int temY){
    visit[chaY][chaX] = true;
    queue<Pos> q;
    q.push({chaY,chaX,0});
    
    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int di = q.front().dist;
        q.pop();
        
        if(r==temY && c==temX) return di/2;//도착
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<0 || nr>=maxi || nc<0 || nc>=maxi) continue;
            if(world[nr][nc]==0) continue;//길이 아님
            if(visit[nr][nc]) continue;//이미 방문
            
            visit[nr][nc] = true;
            q.push({nr,nc,di+1});
        }
    }
    return 0;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    WorldSetting(rectangle);//맵 세팅
    return GetItem(2*characterX,2*characterY,2*itemX,2*itemY);//아이템 먹기
}
