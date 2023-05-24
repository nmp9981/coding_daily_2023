#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos {
    int x, y, isBreak;
};
int n, m;
const int maxi = 1001;
string world[maxi];//지도
int visit[maxi][maxi][2];//거리
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) cin>>world[i];
    memset(visit, -1, sizeof(visit));//초기화
}
//이동
void Move() {
    queue<Pos> q;
    q.push({ 0,0,0 });
    visit[0][0][0] = 1;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int isBreak = q.front().isBreak;
        q.pop();

        if (x == n - 1 && y == m - 1) {//도착
            cout << max(visit[n - 1][m - 1][0], visit[n - 1][m - 1][1]);//출력
            return;
        }

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위조건
            if (visit[nx][ny][isBreak]!=-1) continue;//방문 조건

            if (world[nx][ny] == '0') {//빈칸
                visit[nx][ny][isBreak] = visit[x][y][isBreak]+1;
                q.push({ nx,ny,isBreak });
            }
            else if (world[nx][ny] == '1' && isBreak == 0) {//벽, 아직 안부심
                visit[nx][ny][1] = visit[x][y][0]+1;
                q.push({ nx,ny,isBreak + 1 });
            }
        }
    }
    cout << -1;//최단경로X
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move();//이동
    return 0;
}
