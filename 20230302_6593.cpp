#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Building {
	int zpos,xpos, ypos;
};
int l,r,c;
const int maxi = 31;
string world[maxi][maxi];
int visit[maxi][maxi][maxi];//방문 여부

//6방향
int dz[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };

//입력
bool input() {
	cin >> l>>r>>c;
	if (l + r + c == 0) return false;

	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) cin >> world[k][i];
	}
	return true;
}

//탈출
void Escape() {
	//초기 지점
	queue<Building> q;
	memset(visit, -1, sizeof(visit));//초기화
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (world[k][i][j] == 'S') {
					q.push({ k,i,j });
					visit[k][i][j] = 0;//방문 체크
					break;
				}
			}
		}
	}

	while (!q.empty()) {
		int z = q.front().zpos;
		int x = q.front().xpos;
		int y = q.front().ypos;
		q.pop();

		//도착
		if (world[z][x][y] == 'E') {
			cout << "Escaped in " << visit[z][x][y] << " minute(s).\n";
			return;
		}

		//다음 지점
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위 초과
			if (visit[nz][nx][ny]!=-1) continue;//방문 조건
			if (world[nz][nx][ny] == '#') continue;//장애물 조건

			q.push({nz,nx,ny});
			visit[nz][nx][ny] = visit[z][x][y]+1;//방문 체크
		}
	}
	cout << "Trapped!\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		//입력
		if (input() == false) break;
		else Escape();//탈출		
	}
	return 0;
}
