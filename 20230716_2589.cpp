#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 51;
string world[maxi];
int dist[maxi][maxi];//거리
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
    for (int i = 0; i < n; i++) cin >> world[i];
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) dist[i][j] = -1;
    }
}
//보물 찾기
int TreasureHunt(int i, int j) {
    dist[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({ i,j });
    int totalDist = 0;//총 거리

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //4방 탐색
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (world[nx][ny] == 'W') continue;//바다
            if (dist[nx][ny] != -1) continue;//방문 조건

            dist[nx][ny] = dist[x][y] + 1;
            totalDist = max(dist[nx][ny], totalDist);
            q.push({ nx,ny });
        }
    }
    return totalDist;
}
//시작 위치
void StartPos() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 'L') {
                init();//초기화
                ans = max(ans,TreasureHunt(i,j));//보물찾기
            }
        }
    }
    cout << ans;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    StartPos();//시작 위치
    return 0;
}
