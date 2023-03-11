#include <iostream>
#include <vector>
using namespace std;

int n,m,t;
const int maxi = 2001;
vector<int> graph[maxi];//그래프
bool visit[maxi];//방문 여부
bool flag = false;

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
	cin >> n >>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
//친구 관계
void Friends(int x,int cnt) {
	//ABCDE친구 관계 존재
	if (cnt == 4) {
		flag = true;
		return;
	}
	//다음 친구
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];
		if (visit[next]) continue;//방문 조건
		visit[next] = true;
		Friends(next,cnt+1);
		visit[next] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	for (int i = 0; i < n; i++) {
		visit[i] = true;
		//친구 관계
		Friends(i, 0);
		if (flag == true) break;//친구 관계 존재
		visit[i] = false;
	}
	cout << flag;
	return 0;
}
