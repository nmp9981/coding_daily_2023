#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int k,n,m;
const int maxi = 201;
int world[maxi][maxi];//맵
int visit[maxi][maxi][31];//방문 시간
//12방 탐색
int dx[12] = { -1,1,0,0,-2,-2,-1,-1,1,1,2,2 };
int dy[12] = { 0,0,-1,1,1,-1,2,-2,2,-2,1,-1 };

//입력
void input() {
    cin>>k>>m>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
    memset(visit, -1, sizeof(visit));
}
//이동
void Move() {
    queue<pair<pair<int, int>,int>> q;
    q.push({ {0,0 },0 });//위치, 사용횟수
    visit[0][0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        //도착
        if (x==n-1 && y==m-1) {
            cout << visit[x][y][cnt];
            return;
        }
        //다음 지점
        for (int i = 0; i < 12; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;//범위 조건
            if (world[nx][ny] == 1) continue;//장애물 조건

            if (i < 4) {//일반 이동
                if (visit[nx][ny][cnt]!=-1) continue;//방문 조건
              
                visit[nx][ny][cnt] = visit[x][y][cnt]+1;
                q.push({ {nx,ny},cnt });
            }
            else {//말 이동
                if (cnt < k) {
                    if (visit[nx][ny][cnt + 1]!=-1) continue;
                    
                    visit[nx][ny][cnt + 1] = visit[x][y][cnt]+1;
                    q.push({ {nx,ny},cnt + 1 });
                }
            }
        }
    }
    cout << -1;//도달 불가
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move();//이동
    return 0;
}
