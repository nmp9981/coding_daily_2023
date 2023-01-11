#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//원숭이 위치정보
struct monkey {
	int xpos, ypos, jump;
};
int k,w,h;
const int maxi = 201;
int world[maxi][maxi];//지도
int visit[maxi][maxi][31];//(i,j) k번 jump일때 동작 수 
int dx[12] = { -1,1,0,0,-1,-1,-2,-2,1,1,2,2 };
int dy[12] = { 0,0,-1,1,-2,2,-1,1,-2,2,-1,1 };

//입력
void input() {
	cin >> k>>w>>h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> world[i][j];
	}
	memset(visit, -1, sizeof(visit));//초기화
}
//원숭이 이동
void Move() {
	queue<monkey> q;
	q.push({ 0,0,0 });//초기 위치
	visit[0][0][0] = 0;

	while (!q.empty()) {
		//현재 위치
		int x = q.front().xpos;
		int y = q.front().ypos;
		int cnt = q.front().jump;
		q.pop();

		//도착
		if (x == h - 1 && y == w - 1) {
			cout << visit[x][y][cnt];//출력
			return;
		}
		//다음 위치
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;//범위 조건
			if (world[nx][ny] == 1) continue;//장애물 조건

			//일반 이동
			if (i < 4) {
				if (visit[nx][ny][cnt] == -1) {//미방문
					visit[nx][ny][cnt] = visit[x][y][cnt]+1;
					q.push({ nx,ny,cnt });
				}
			}
			else {//말 이동
				if (visit[nx][ny][cnt + 1] == -1 && cnt<k) {//최대 k번
					visit[nx][ny][cnt + 1] = visit[x][y][cnt]+1;
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
	cout << -1;//도달 불가
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	Move();//이동
	return 0;
}
