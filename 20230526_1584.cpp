#include <iostream>
#include <deque>
using namespace std;

struct Pos {
    int x, y, life;
};
int n, m;
const int maxi = 501;
int world[maxi][maxi];//월드
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    //위험구역
    for (int k = 0; k < n; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(y1, y2); j <= max(y1, y2); j++) world[i][j] = 1;
        }
    }
    cin >> m;
    //죽음구역
    for (int k = 0; k < m; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(y1, y2); j <= max(y1, y2); j++) world[i][j] = 2;
        }
    }
}
//이동
void Move() {
    visit[0][0] = true;
    deque<Pos> dq;
    dq.push_back({ 0,0,0 });

    while (!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        int life = dq.front().life;
        dq.pop_front();

        //도착
        if (x == maxi - 1 && y == maxi - 1) {
            cout << life;
            return;
        }
        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            
            visit[nx][ny] = true;
            if (world[nx][ny] == 0) dq.push_front({ nx,ny,life });//안전
            else if (world[nx][ny] == 1)  dq.push_back({ nx,ny,life + 1 });//위험
        }
    }
    cout << -1;//갈 수 없음
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move();//이동
    return 0;
}
