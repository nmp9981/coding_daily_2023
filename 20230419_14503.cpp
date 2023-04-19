#include <iostream>
#include <queue>
using namespace std;

struct RobotInfo {
    int x, y, dir;
};
class Robot {
private:
    int n, m,r,c,d;
    static const int maxi = 51;
    int world[maxi][maxi];//지도
    //4방 탐색
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
public:
    Robot() {};//디폴트 생성자
    void input();//입력
    void Move();//이동
};
//입력
void Robot::input() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cin >> world[i][j];
    }
}
//이동
void Robot::Move() {
    queue<RobotInfo> q;
    q.push({ r,c,d });
    int total = 0;//청소하는 칸의 개수

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();

        //청소하기
        if (world[x][y] == 0) {
            world[x][y] = 2;
            total++;
        }

        //주변 4칸
        int cleanCnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (world[nx][ny] == 0) cleanCnt++;//청소되지 않은 빈칸
        }
        if (cleanCnt == 0) {//청소 X인 칸이 없다
            int bx = x - dx[dir];//후진
            int by = y - dy[dir];
            if (world[bx][by] == 1) break;//벽
            else q.push({ bx,by,dir });
        }
        else {//청소 X인 칸이 있다
            int ndir = (dir +3)%4;//반시계 회전
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if (world[nx][ny] == 0) q.push({ nx,ny,ndir });//이동까지
            else q.push({ x,y,ndir });//회전만
        }
    }
    cout << total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Robot robot;
    robot.input();
    robot.Move();
    return 0;
}
