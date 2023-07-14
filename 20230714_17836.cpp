#include <iostream>
#include <queue>
using namespace std;

int n, m,t;
const int inf = 1000001;
const int maxi = 101;
int gramTime = inf;
int minTime = inf;
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m>>t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            visit[i][j] = -1;
        }
    }
}
//공주님 구하기
void Princess() {
    queue<pair<int, int>> q;
    visit[0][0] = 0;
    q.push({ 0,0 });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //그람
        if (world[x][y] == 2) {
            gramTime = visit[x][y] + abs(n - 1 - x) + abs(m - 1 - y);
        }
        //도착
        if (x == n - 1 && y == m - 1) {
            minTime = visit[x][y];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny] != -1) continue;//방문 여부
            if (world[nx][ny] == 1) continue;//장애물

            visit[nx][ny] = visit[x][y] + 1;
            q.push({ nx,ny });
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Princess();//공주님 구하기
    //결과
    minTime = min(minTime, gramTime);
    if (minTime <= t) cout << minTime;
    else cout << "Fail";
    return 0;
}
