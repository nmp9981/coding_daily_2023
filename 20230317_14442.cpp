#include <iostream>
#include <queue>
using namespace std;

int n,m,k;
const int maxi = 1001;
string world[maxi];//지도
int visit[maxi][maxi][11];//벽 k개 부쉈을때 (i,j)에서의 최단거리
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n>>m>>k;
	for (int i = 0; i < n; i++) cin >> world[i];
}

//Move
void Move() {
	visit[0][0][0] = 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		//도착
		if (x == n - 1 && y == m - 1) {
			cout << visit[x][y][cnt];
			return;
		}
		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
			
			if (world[nx][ny] == '1' && cnt<k) {//벽
				if (visit[nx][ny][cnt + 1] == 0) {
					visit[nx][ny][cnt + 1] = visit[x][y][cnt] + 1;
					q.push({ {nx,ny},cnt + 1 });
				}
			}
			else if(world[nx][ny] == '0') {//벽이 아님
				if (visit[nx][ny][cnt] == 0) {
					visit[nx][ny][cnt] = visit[x][y][cnt] + 1;
					q.push({{nx,ny},cnt});
				}
			}
		}
	}
	cout << -1;//불가능
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Move();//이동
	return 0;
}
