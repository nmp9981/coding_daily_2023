#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int times = 0;
const int maxi = 101;
int world[maxi][maxi];//월드
bool visit[maxi][maxi];//방문 여부
int amountCheese = 0;//치즈양
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
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) amountCheese++;//치즈양
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
//외부와 접촉하는 부분
void OutConnect(int i,int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visit[i][j] = true;
    vector<pair<int, int>> connect;
    connect.push_back({ i,j });
    bool isOut = false;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) isOut = true;//외부와 접촉

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            if (world[nx][ny] !=0) continue;//장애물 조건

            q.push({ nx,ny });
            connect.push_back({ nx,ny });
            visit[nx][ny] = true;
        }
    }
    if (isOut) {//외부와 접촉
        for (int k = 0; k < connect.size(); k++) {
            int nx = connect[k].first;
            int ny = connect[k].second;
            world[nx][ny] = 2;
        }
    }
}
//빈칸 탐색
void BlankSearch() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && world[i][j] == 0) OutConnect(i, j);
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
                        world[i][j] = 0;//외부 접촉시 녹이기
                        break;
                    }
                }
            }
        }
    }
}
//치즈세기
int CountCheese() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) cnt++;
        }
    }
    if (cnt>0) amountCheese = cnt;//갱신
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        times++;//시간 경과
        init();//초기화
        BlankSearch();//빈칸 탐색
        Melt();//녹이기
        if(CountCheese()==0) break;//치즈양
    }
    //출력
    cout << times << "\n";
    cout << amountCheese;
    return 0;
}
