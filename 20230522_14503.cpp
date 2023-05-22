#include <iostream>
#include <queue>
using namespace std;

//로봇 정보
struct Robot {
    int x, y, dir;
};
int n,m,r,c,d;
const int maxi = 51;
int room[maxi][maxi];//방
//북동남서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//입력
void input() {
    cin >> n>>m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> room[i][j];
    }
}
//청소
void Clean() {
    queue<Robot> q;
    q.push({ r,c,d });

    room[r][c] = 2;
    int cnt = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();

        //빈칸 청소
        if (room[x][y] == 0) {
            room[x][y] = 2;
            cnt += 1;
        }
        //주변 탐색
        bool isBlank = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (room[nx][ny] == 0) {
                isBlank = true;//빈칸
                break;
            }
        }
        //빈칸 유무
        if (isBlank == true) {
            int ndir = (dir + 3) % 4;//반시계 회전
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if (room[nx][ny] == 0) q.push({ nx,ny,ndir });
            else q.push({ x,y,ndir });
        }
        else {
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            if (room[nx][ny] == 1) break;///멈춤
            else q.push({ nx,ny,dir });
        }
    }
    cout << cnt;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Clean();//청소
    return 0;
}
