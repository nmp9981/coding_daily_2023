#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 51;
string world[maxi];//지도
int visit[maxi][maxi];//최단거리
int maxTimes = 0;//보물 찾는 시간
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
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//보물 찾기
int Tresure(int i, int j) {
    visit[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({ i, j });
    int times = 0;

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
            if (world[nx][ny] == 'W') continue;//바다 인가?

            visit[nx][ny] = visit[x][y] + 1;//거리 증가
            times = max(times, visit[nx][ny]);//최대 거리 갱신
            q.push({ nx,ny });
        }
    }
    return times;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    //시작 지점
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 'L') {
                init();//초기화
                maxTimes = max(maxTimes,Tresure(i, j));//보물 찾기
            }
        }
    }
    cout << maxTimes;//출력
    return 0;
}
