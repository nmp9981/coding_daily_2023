#include <iostream>
#include <queue>
using namespace std;

struct RobotInfo {
	int xpos, ypos, direction;
};
class Robot {
private:
	static const int maxi = 51;
	int n, m,r,c,d;
	int room[maxi][maxi];
	int cnt = 0;
	//4방 탐색
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
public:
	Robot() {}
	void input();//입력
	void Clean();//청소
};

//입력
void Robot::input() {
	cin >> n>>m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> room[i][j];
	}
}
//청소
void Robot::Clean() {
	queue<RobotInfo> q;
	q.push({ r,c,d });

	while (!q.empty()) {
		int x = q.front().xpos;
		int y = q.front().ypos;
		int dir = q.front().direction;
		q.pop();

		//청소하기
		if (room[x][y] == 0) {
			room[x][y] = 2;
			cnt++;
		}

		//주변 4칸 탐색
		bool isBlank = false;//빈칸이 있는가?
		for (int i = 0; i < 4; i++) {
			int ndir = (dir-i+3)%4;//다음 방향
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (room[nx][ny] == 0) {//빈칸
				isBlank = true;
				q.push({ nx,ny,ndir });
				break;
			}
		}
		//빈칸이 없다
		if (!isBlank) {
			//후진 시도
			int nx = x - dx[dir];int ny = y - dy[dir];
			if (room[nx][ny] == 1) {//벽
				cout << cnt;
				return;
			}
			else q.push({ nx,ny,dir });//벽X
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Robot robot;
	robot.input();//입력
	robot.Clean();//청소
	return 0;
}
