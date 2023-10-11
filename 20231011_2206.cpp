#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
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
//초기화
void Init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j][0] = -1;
            visit[i][j][1] = -1;
        }
    }
}
//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//이동
void Move() {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{0,0} });
    visit[0][0][0] = 1;//시작칸 포함

    while (!q.empty()) {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == n - 1 && y == m - 1) {//도착
            cout << max(visit[x][y][0], visit[x][y][1]);
            return;
        }

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;//범위초과
            
            //벽을 부순다.
            if (world[nx][ny] == '1') {
                if (visit[nx][ny][1] == -1 && cnt == 0) {
                    visit[nx][ny][cnt + 1] = visit[x][y][cnt] + 1;
                    q.push({ cnt + 1,{nx,ny} });
                }
            }
            //그냥 이동
            if (world[nx][ny] == '0') {
                if (visit[nx][ny][cnt] == -1) {
                    visit[nx][ny][cnt] = visit[x][y][cnt] + 1;
                    q.push({ cnt,{nx,ny} });
                }
            }
        }
    }
    cout << -1;//이동 불가
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Init();//초기화
    Move();//이동
    return 0;
}
