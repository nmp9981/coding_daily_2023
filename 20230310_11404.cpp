#include <iostream>
using namespace std;

int n,m;
const int maxi = 101;
const int inf = 300000001;
int city[maxi][maxi];

//min
inline int min(int a,int b) {
	return a > b ? b : a;
}
//초기화
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = inf;
		}
	}
}
//입력
void input() {
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = min(c,city[a][b]);//노선이 여러개
	}
}
//플로이드
void Floyd() {
	for (int k = 1; k <= n; k++) {//경유 지점
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
		}
	}
}
//출력
void Output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == inf) cout << 0 << " ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();//초기화
	input();//입력
	Floyd();//플로이드
	Output();//출력
	return 0;
}
