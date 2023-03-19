#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 8;
int world[maxi][maxi];//연구소
bool visit[maxi][maxi];//방문 여부
int copyWorld[maxi][maxi];//연구소 (복사)
int safe = 0;//안전 지대 개수
vector<pair<int, int>> canWall;//벽을 세울 수 있는 공간
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> world[i][j];
			if (world[i][j] == 0) canWall.push_back({ i,j });
		}
	}
}

//확산
void Spread() {
	//맵 세팅
	queue<pair<int, int>> virus;//바이러스
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyWorld[i][j] = world[i][j];//맵 복사
			if (copyWorld[i][j] == 2) virus.push({ i,j });
		}
	}
	
	//확산
	while (!virus.empty()) {
		int x = virus.front().first;
		int y = virus.front().second;
		virus.pop();

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
			if (copyWorld[nx][ny] == 0) {//빈칸
				virus.push({ nx,ny });
				copyWorld[nx][ny] = 2;
			}
		}
	}
}
//안전 지대
int SafeArea() {
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyWorld[i][j] == 0) area++;
		}
	}
	return area;
}
//벽 세우기
void InstallWall(int idx,int cnt) {
	//벽을 모두 세움
	if (cnt == 3) {
		Spread();//확산
		safe = max(safe,SafeArea());//안전 지대
		return;
	}

	//다음 지점
	for (int k = idx; k < canWall.size(); k++) {
		world[canWall[k].first][canWall[k].second] = 1;//벽 설치
		InstallWall(k + 1,cnt+1);
		world[canWall[k].first][canWall[k].second] = 0;//벽 해제
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	InstallWall(0, 0);//벽 세우기
	cout << safe;//출력
	return 0;
}
