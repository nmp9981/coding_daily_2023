#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct Pos {
    int x, y, dist;//좌표 거리
};
int n,m;
const int maxi = 501;
int world[maxi][maxi];//월드
bool visit[maxi][maxi];//방문 지역
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int k = 0; k < n; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(y1, y2); j <= max(y1, y2); j++) world[i][j] = 1;
        }
    }
    cin >> m;
    for (int k = 0; k < m; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = min(x1, x2); i <= max(x1, x2); i++) {
            for (int j = min(y1, y2); j <= max(y1, y2); j++) world[i][j] = 2;
        }
    }
}
//이동
int Move() {
    visit[0][0] = true;
    deque<Pos> dq;
    dq.push_back({ 0,0,0 });

    while (!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        int curDist = dq.front().dist;
        dq.pop_front();

        if (x == maxi-1 && y == maxi-1) return curDist;//도착

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위 초과
            if (visit[nx][ny]) continue;//이미 방문
            if (world[nx][ny] == 2) continue;//죽음 지역

            visit[nx][ny] = true;
            if (world[nx][ny] == 0) dq.push_front({ nx,ny,curDist });
            else dq.push_back({ nx,ny,curDist + 1 });
        }
    }
    return -1;//도달 불가
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Move();//이동
    return 0;
}
