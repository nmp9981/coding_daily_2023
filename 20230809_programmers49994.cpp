#include <string>
using namespace std;

const int maxi = 11;
bool visit[maxi][maxi][maxi][maxi];//방문 여부
int nx,ny;

//이동
int Move(string dirs){
    int x = 5;int y = 5;
    int cnt = 0;
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            nx = x-1;
            ny = y;
        }else if(dirs[i]=='D'){
            nx = x+1;
            ny = y;
        }else if(dirs[i]=='L'){
            nx = x;
            ny = y-1;
        }else if(dirs[i]=='R'){
            nx = x;
            ny = y+1;
        }
        if(nx<0 || nx>=maxi || ny<0 || ny>=maxi) continue;//범위조건
        if(!visit[nx][ny][x][y] && !visit[x][y][nx][ny]){
            visit[nx][ny][x][y] = true;
            visit[x][y][nx][ny] = true;
            cnt++;
        } 
        x = nx;y = ny;
    }
    return cnt;
}
int solution(string dirs) {
    return Move(dirs);
}
