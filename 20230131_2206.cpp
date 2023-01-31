#include <iostream>
#include <queue>
using namespace std;

//벽 정보
struct Wall {
    int xpos, ypos,breakCount, dist;//위치,벽 부순 횟수, 이동 거리
};

int n,m;
const int maxi = 1001;
string world[maxi];//지도
bool visit[maxi][maxi][2];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//이동
void Move() {
    visit[0][0][0] = true;
    queue<Wall> q;
    q.push({ 0,0,0,1 });//시작점 포함

    while (!q.empty()) {
        int x = q.front().xpos;//x좌표
        int y = q.front().ypos;//y좌표
        int cnt = q.front().breakCount;//벽을 부순 횟수
        int Dist = q.front().dist;//이동 칸수
        q.pop();

        //도착
        if (x == n - 1 && y == m - 1) {
            cout << Dist;
            return;
        }
        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            
            if (world[nx][ny] == '0' && visit[nx][ny][cnt]==false) {//빈칸이고 미방문
                visit[nx][ny][cnt] = true;
                q.push({ nx, ny, cnt, Dist + 1 });
            }
            else if (world[nx][ny] == '1' && cnt==0) {//벽이고 아직 안부숨
                if (visit[nx][ny][cnt + 1] == false) {//미방문이면
                    visit[nx][ny][cnt + 1] = true;
                    q.push({ nx,ny,cnt + 1,Dist + 1 });
                }
            }
        }
    }
    cout << -1;//불가능
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Move();//이동
    return 0;
}
