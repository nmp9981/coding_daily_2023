#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
const int maxi = 51;
string world[maxi];//지도
int visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void Init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) visit[i][j] = -1;
    }
}
//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//탐색
int bfs(int i,int j) {
    visit[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({ i,j });
    int length = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny] >= 0) continue;
            if (world[nx][ny] == 'W') continue;

            visit[nx][ny] = visit[x][y] + 1;
            length = max(length, visit[nx][ny]);
            q.push({ nx,ny });
        }
    }
    return length;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 'L') {
                Init();//초기화
                ans = max(ans,bfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}
