#include <iostream>
#include <queue>
using namespace std;

int n,m;
int day = 0;
int CanGo = 0;
bool escape = false;
const int maxi = 1001;
string world[maxi];
queue<pair<int, int>> FireQ;
queue<pair<int, int>> JihunQ;
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        cin >> world[i];
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 'J') {
                visit[i][j] = true;
                JihunQ.push({ i,j });
            }
            else if (world[i][j] == 'F') FireQ.push({ i,j });
        }
    }
}
//불 확산
void FireSpread() {
    int FireSize = FireQ.size();
    for (int i = 0; i < FireSize; i++) {
        int x = FireQ.front().first;
        int y = FireQ.front().second;
        FireQ.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 초과
            if (world[nx][ny] == 'F') continue;//이미 확산
            if (world[nx][ny] == '#') continue;//벽

            world[nx][ny] = 'F';//확산
            FireQ.push({ nx,ny });
        }
    }
}
//이동
void Move() {
    CanGo = 0;
    int JihunSize = JihunQ.size();
    for (int i = 0; i < JihunSize; i++) {
        int x = JihunQ.front().first;
        int y = JihunQ.front().second;
        JihunQ.pop();
        
        //탈출
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            cout << day+1;
            escape = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 초과
            if (visit[nx][ny]) continue;//이미 방문
            if (world[nx][ny] == '#') continue;//벽
            if (world[nx][ny] == 'F') continue;//불

            CanGo++;
            visit[nx][ny] = true;//방문
            JihunQ.push({ nx,ny });
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        FireSpread();//불 확산
        Move();//이동
        if (escape) break;//탈출
        if (CanGo == 0) {//이동 불가
            cout << "IMPOSSIBLE";
            break;
        }
        day++;
    }
    return 0;
}
