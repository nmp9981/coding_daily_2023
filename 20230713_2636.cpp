#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int times = 0;//시간
const int maxi = 101;
int world[maxi][maxi];//맵
bool visit[maxi][maxi];//방문 여부
int cheeseCount = 0;//치즈 개수
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) visit[i][j] = false;
    }
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) cheeseCount++;
            if (world[i][j] == 2) world[i][j] = 0;
        }
    }
}
//외부 공기 접촉
void isAir(int i, int j) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> Edge;
    q.push({ i,j });
    Edge.push_back({ i,j });
    bool isOut = false;
    visit[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위조건
            if (visit[nx][ny]) continue;//방문조건
            if (world[nx][ny] == 1) continue;//치즈

            if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) isOut = true;
            visit[nx][ny] = true;
            q.push({ nx,ny });
            Edge.push_back({ nx,ny });
        }
    }
    //바깥 지점만
    if (isOut) {
        for (int k = 0; k < Edge.size(); k++) {
            int x = Edge[k].first;
            int y = Edge[k].second;
            world[x][y] = 2;
        }
    }
}
//검사
void Inspect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && world[i][j] == 0) isAir(i, j);
        }
    }
}
//녹이기
void Melt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) {//치즈
                //4방 탐색
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    //녹인다.
                    if (world[nx][ny] == 2) {
                        world[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}
//남은 치즈 개수
int CheeseCount() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j]==1) cnt++;
        }
    }
    if (cnt > 0) cheeseCount = cnt;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        times++;//시간 흐름
        init();//초기화
        Inspect();//검사
        Melt();//녹이기
        if (CheeseCount() == 0) break;//남은 치즈 개수
    }
    //출력
    cout << times << "\n";
    cout << cheeseCount;
    return 0;
}
