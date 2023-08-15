#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
const int maxi = 1001;
const int inf = 300000000;
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 시간
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) visit[i][j] = -1;
    }
}
//입력
void input() {
    cin>>m>>n;
    memset(visit, -1,sizeof(visit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//토마토
void Tomato() {
    queue<pair<int, int>> q;
    int day = 0;
    //이미 익은 토마토
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) {
                q.push({ i,j });
                visit[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            
            if (visit[nx][ny] != -1) continue;//방문 조건
            
            //안익은 토마토
            if (world[nx][ny] == 0) {
                q.push({ nx,ny });
                visit[nx][ny] = visit[x][y] + 1;
                world[nx][ny] = 1;//익음
                day = max(day, visit[nx][ny]);
            }
        }
    }
    //확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0) day = -1;
        }
    }
    cout << day;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Tomato();//토마토 익기
    return 0;
}
