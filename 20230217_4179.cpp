#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int r, c;
const int maxi = 1001;
string maze[maxi];//미로
bool jihunVisit[maxi][maxi];//지훈 방문 여부
queue<pair<int, int>> fireQ;
queue<pair<int, int>> jihunQ;
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> maze[i];
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') {//지훈 초기위치
				jihunVisit[i][j] = true;
				jihunQ.push({ i,j });
			}
			if (maze[i][j] == 'F') fireQ.push({ i,j });//불 초기위치
		}
	}
}

//불확산
void SpreadFire() {
	int fireSize = fireQ.size();
	for (int i = 0; i < fireSize; i++) {
		int fx = fireQ.front().first;
		int fy = fireQ.front().second;
		fireQ.pop();

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nfx = fx + dx[k];
			int nfy = fy + dy[k];

			if (nfx < 0 || nfx >= r || nfy < 0 || nfy >= c) continue;//범위조건
			if (maze[nfx][nfy] == '#') continue;//벽
			if (maze[nfx][nfy] == 'F') continue;//이미 확산

			fireQ.push({ nfx,nfy });
			maze[nfx][nfy] = 'F';//불 번짐
		}
	}
}
//지훈 탈출
bool JihunMove() {
	int jihunSize = jihunQ.size();
	int canMove = 0;//이동 가능한 지점
	for (int i = 0; i < jihunSize; i++) {
		int jx = jihunQ.front().first;
		int jy = jihunQ.front().second;
		jihunQ.pop();

		//탈출
		if (jx == 0 || jx == r - 1 || jy == 0 || jy == c - 1) {
			return true;
		}
		//다음 지점
		for (int k = 0; k < 4; k++) {
			int njx = jx + dx[k];
			int njy = jy + dy[k];

			if (njx < 0 || njx >= r || njy < 0 || njy >= c) continue;//범위조건
			if (maze[njx][njy] == '#') continue;//벽
			if (maze[njx][njy] == 'F') continue;//불
			if (jihunVisit[njx][njy] == true) continue;//이미 방문

			canMove++;
			jihunQ.push({ njx,njy });
			jihunVisit[njx][njy] = true;//방문 체크
		}
	}
	if (canMove == 0) {//탈출불가
		cout << "IMPOSSIBLE";
		exit(0);
	}
	return false;
}
//탈출
void Escape() {
	int times = 0;
	while (true) {
		SpreadFire();//불확산
		if (JihunMove()) {//지훈 탈출
			cout << times + 1;//다음 지점에서 탈출
			break;
		}
		else times++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Escape();//탈출
	return 0;
}
