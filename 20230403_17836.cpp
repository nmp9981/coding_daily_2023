#include <iostream>
#include <queue>
using namespace std;

struct Hero {
    int x, y, cnt;
};
int n,m,t;
const int maxi = 101;
const int inf = 10000001;
int castle[maxi][maxi];//성
bool visit[maxi][maxi];//방문 여부
int minTime = inf;
int gramTime = inf;
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//그람
int Gram(int xpos, int ypos, int times) {
    return (n - xpos) + (m - ypos) + times;
}
//입력
void input() {
    cin >> n>>m>>t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> castle[i][j];
    }
}
//탈출
void Escape(int startX,int startY) {
    queue<Hero> q;
    q.push({ startX,startY,0 });
    visit[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int times = q.front().cnt;
        q.pop();

        //도착
        if (x == n && y == m) {
            minTime = times;
            return;
        }
        //그람
        if (castle[x][y] == 2) gramTime = Gram(x, y,times);

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;//범위 조건
            if (castle[nx][ny] == 1) continue;//장애물
            if (visit[nx][ny]) continue;//방문 조건

            visit[nx][ny] = true;
            q.push({ nx,ny,times + 1 });
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Escape(1,1);//탈출
    //결과
    minTime = min(minTime, gramTime);
    if (minTime > t) cout << "Fail";
    else cout << minTime;
    return 0;
}
