#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 101;
const int inf = 1000000;
string maze[maxi];//미로
int wall[maxi][maxi];//(i,j)까지 벽을 몇개 뚫었는가?
int dx[4] = { -1,1,0,0 };//4방 탐색
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> m>>n;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) wall[i][j] = inf;
    }
}
//bfs탐색
void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    wall[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;//범위 조건

            //벽o
            if (maze[nx][ny]=='1') {
                if (wall[nx][ny] > wall[x][y] + 1) {
                    wall[nx][ny] = wall[x][y] + 1;
                    q.push({ nx,ny });
                }
            }
            //벽x
            if (maze[nx][ny] == '0') {
                if (wall[nx][ny] > wall[x][y]) {
                    wall[nx][ny] = wall[x][y];
                    q.push({ nx,ny });
                }
            }
        }
    }
    cout << wall[n - 1][m - 1];//출력
}

int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    bfs();// bfs탐색
    return 0;
}
