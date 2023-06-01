#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int year = 0;//연도
const int maxi = 301;
int world[maxi][maxi];//배열
int meltAmount[maxi][maxi];//녹는양
bool visit[maxi][maxi];//방문 여부
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//탐색
int bfs(int i, int j) {
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push({ i,j });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            if (world[nx][ny] == 0) continue;//바닷물

            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    return 1;
}
//두덩이 이상인가?
int Ice() {
    int lump = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && world[i][j]>0) lump += bfs(i, j);
        }
    }
    return lump;
}
//녹이기
void Melt() {
    memset(meltAmount, 0, sizeof(meltAmount));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0) continue;//바다

            int amount = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
                if (world[nx][ny] == 0) amount++;//바다
            }
            meltAmount[i][j] = amount;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            world[i][j] = max(0, world[i][j] - meltAmount[i][j]);
        }
    }
}
//다 녹았는가?
bool AllMelt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] > 0) return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        memset(visit, false, sizeof(visit));//초기화
        if (Ice()>=2) break;//덩어리 개수 검사
        Melt();//녹이기

        //다 녹았는가?
        if (AllMelt()) {
            year = 0;
            break;
        }
        year++;//시간 흐름
    }
    cout << year;//출력
    return 0;
}
