#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 101;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
int cheeseCount = 0;//치즈 개수
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) cheeseCount++;//치즈 개수
        }
    }
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            if (world[i][j] == 2) world[i][j] = 0;
        }
    }
}
//외부 연결 여부
void OutContact(int i, int j) {
    bool isOut = false;
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push({ i,j });
    vector<pair<int, int>>  connect;
    connect.push_back({ i,j });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) isOut = true;//외부 접촉

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 여부
            if (world[nx][ny] != 0) continue;//빈공간 여부

            visit[nx][ny] = true;
            q.push({ nx,ny });
            connect.push_back({ nx,ny });
        }
    }
    //외부 공기와 접촉한 것만
    if (isOut) {
        for (int k = 0; k < connect.size(); k++) {
            int nx = connect[k].first;
            int ny = connect[k].second;
            world[nx][ny] = 2;
        }
    }
}
//외부 접촉
void Outside() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0 && !visit[i][j]) OutContact(i, j);
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
                    if (world[nx][ny] == 2) {//외부 접촉
                        world[i][j] = 0;//녹임
                        break;
                    }
                }
            }
        }
    }
}
//치즈 개수 세기
int CheeseCount() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) cnt++;
        }
    }
    if (cnt > 0) cheeseCount = cnt;//갱신
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    int times = 0;
    while (true) {
        times++;
        init();//초기화
        Outside();//외부 접촉
        Melt();//녹이기

        if (CheeseCount() == 0) break;//다 녹았는가?
    }
    //출력
    cout << times<<"\n";
    cout << cheeseCount;
    return 0;
}
