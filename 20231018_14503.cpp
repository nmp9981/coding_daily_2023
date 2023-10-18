#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//위치 정보
struct Pos {
    int xpos, ypos, direction;
};
int n,m,r,c,d;
const int maxi = 51;
int world[maxi][maxi];//지도
//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//청소
void Clean() {
    int cnt = 0;
    queue<Pos> q;
    q.push({ r,c,d });

    while (!q.empty()) {
        int x = q.front().xpos;
        int y = q.front().ypos;
        int dir = q.front().direction;
        q.pop();
        
        //청소
        if (world[x][y] == 0) {
            world[x][y] = 2;
            cnt++;
        }
        //4방탐색
        int notClean = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (world[nx][ny] == 0) {//빈칸 발견
                notClean = 1;
                break;
            }
        }

        //반칸이 있다.
        if (notClean == 1) {
            int nextDir = (dir +3)%4;
            int nx = x + dx[nextDir];
            int ny = y + dy[nextDir];
            if (world[nx][ny] == 0) q.push({ nx,ny,nextDir });
            else q.push({ x,y,nextDir });
        }
        else {
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            if (world[nx][ny] != 1) q.push({ nx,ny,dir });
            else break;//벽
        }
    }
    cout << cnt;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Clean();//청소
    return 0;
}
