#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 101;
int colorArea = 0;//영역 수
string world[maxi];//지도
bool visit[maxi][maxi];//방문 여부
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> world[i];
}
//초기화
void init() {
	colorArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) visit[i][j] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (world[i][j] == 'G') world[i][j] = 'R';//색맹
		}
	}
}

//색약 bfs
int ColorBfs(int i, int j, char color) {
	visit[i][j] = true;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
			if (visit[nx][ny]) continue;//이미 방문
			if (world[nx][ny] == color) {//색 일치
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}
	return 1;
}
//색약
void ColorWeakness() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) colorArea += ColorBfs(i, j, world[i][j]);
		}
	}
	cout << colorArea << " ";//출력
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	ColorWeakness();//색약X
	init();//초기화
	ColorWeakness();//색약
	return 0;
}
