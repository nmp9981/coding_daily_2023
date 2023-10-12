#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int restCount = 0;
const int maxi = 101;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
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
            visit[i][j] = false;
            if (world[i][j] == 2) world[i][j] = 0;
        }
    }
}
//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) restCount++;//치즈
        }
    }
}
//탐색
void bfs(int i,int j) {
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push({ i,j });
    vector<pair<int, int>> connect;
    connect.push_back({ i,j });
    bool isOut = false;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //바깥지점
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) isOut = true;
        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny]) continue;
            if (world[nx][ny]!=0) continue;

            visit[nx][ny] = true;
            connect.push_back({ nx,ny });
            q.push({ nx,ny });
        }
    }
    //외부 접촉
    if (isOut) {
        for (int k = 0; k < connect.size(); k++) {
            world[connect[k].first][connect[k].second] = 2;
        }
    }
}
//검사
void Inspect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && world[i][j]==0) bfs(i, j);
        }
    }
}
//녹이기
void Melt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) {//치즈
                for (int k = 0; k < 4; k++) {//4방 탐색
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (world[nx][ny] == 2) {
                        world[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}
//치즈 개수
int CountCheeze() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) cnt++;
        }
    }
    if (cnt > 0) restCount = cnt;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    int times = 0;
    while (true) {
        times++;
        Init();//초기화
        Inspect();//검사
        Melt();//녹이기
        if (CountCheeze()==0) break;//모두 녹음
    }
    cout << times << "\n" << restCount;//출력
    return 0;
}
