#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 51;
const int inf = 10000000;
string world[maxi];//지도
int visit[maxi][maxi];//방문 횟수
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> world[i];
    //초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visit[i][j] = inf;
    }
}
//이동
void Move() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visit[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //4방 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            
            //흰방
            if (world[nx][ny] == '1') {
                if (visit[nx][ny] > visit[x][y]) {
                    visit[nx][ny] = visit[x][y];
                    q.push({ nx,ny });
                }
            }
            //검은방
            if (world[nx][ny] == '0') {
                if (visit[nx][ny] > visit[x][y]+1) {
                    visit[nx][ny] = visit[x][y]+1;
                    q.push({ nx,ny });
                }
            }
        }
    }
    cout<<visit[n - 1][n - 1];//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Move();//이동
    return 0;
}
