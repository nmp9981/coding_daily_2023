#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d;
const int maxi = 1000001;
bool visit[maxi];
queue<pair<int,int>> q;

//입력
void input() {
	cin >> f >> s >> g >> u >> d;
}
//엘리베이터
void Elev() {
	q.push({ s,0 });
	visit[s] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		//도착
		if (x == g) {
			cout << cnt;
			return;
		}
		//다음 지점
		int nextUp = x + u;
		if (nextUp <= f && !visit[nextUp]) {//범위내, 미방문
			q.push({ nextUp,cnt + 1 });
			visit[nextUp] = true;
		}
		
		int nextDown = x -d;
		if (nextDown >0 && !visit[nextDown]) {//범위내, 미방문
			q.push({ nextDown,cnt + 1 });
			visit[nextDown] = true;
		}
	}
	cout << "use the stairs";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Elev();//엘리베이터
	return 0;
}
