#include <iostream>
#include <queue>
using namespace std;

int n,k;
const int maxi = 200001;
bool visit[maxi];

//입력
void input() {
	cin >> n>>k;
}
//숨바꼭질
void HideAndSeek() {
	queue<pair<int, int>> q;
	q.push({ n,0 });
	visit[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//도착
		if (x == k) {
			cout << cnt;
		}
		//순간이동
		int telpo = x * 2;
		if (telpo < maxi) {//범위내에 들고
			if (!visit[telpo]) {//미방문
				visit[telpo] = true;
				q.push({ telpo,cnt });
			}
		}
		//걷기
		if (x - 1 >= 0) {//범위내에 들고
			if (!visit[x - 1]) {//미방문
				visit[x - 1] = true;
				q.push({ x - 1,cnt+1 });
			}
		}
		if (x + 1 < maxi) {//범위내에 들고
			if (!visit[x + 1]) {//미방문
				visit[x + 1] = true;
				q.push({ x + 1,cnt + 1 });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	HideAndSeek();//숨바꼭질
	return 0;
}
