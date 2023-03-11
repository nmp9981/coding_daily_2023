#include <iostream>
#include <queue>
using namespace std;

int n,m,t;
const int maxi = 101;
const int inf = 10000010;
int castle[maxi][maxi];//성
bool visit[maxi][maxi];//방문 여부
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int gramTime = inf;
int Times = inf;

//min
inline int min(int a,int b) {
	return a > b ? b : a;
}
//그람
int Gram(int x, int y) {
	return abs(x - n) + abs(y - m);
}
//입력
void input() {
	cin >> n >>m>>t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> castle[i][j];
	}
}
//공주 구출
void Escape() {
	queue<pair<pair<int,int>,int>> q;
	q.push({ { 1,1 },0 });
	visit[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		//도착
		if (x == n && y == m) {
			Times = cnt;
			return;
		}
		//그람 발견
		if (castle[x][y] == 2) gramTime = cnt+Gram(x, y);
		//10초 초과
		if (cnt > t) {
			Times = cnt;
			return;
		}

		//다음 지점
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;//범위 초과
			if (visit[nx][ny]) continue;//방문 여부
			if (castle[nx][ny] == 1) continue;//벽

			visit[nx][ny] = true;
			q.push({ {nx,ny},cnt + 1 });
		}
	}
	Times = inf;//못 구함
}
//시간 체크
void Check() {
	Times = min(Times, gramTime);
	if (Times > t) cout << "Fail";
	else cout << Times;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Escape();//공주 구출
	Check();//시간 체크
	return 0;
}
