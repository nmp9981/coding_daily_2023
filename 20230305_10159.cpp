#include <iostream>
using namespace std;

int n,m;
const int maxi = 101;
const int inf = 100000007;
int weight[maxi][maxi];//무게 비교
int obj[maxi];//물건 개수

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		weight[a][b] = 1;
	}
}
//초기화
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) weight[i][j] = 0;
			else weight[i][j] = inf;
		}
	}
}
//물건 개수 세기
void CountObj() {
	//행기준
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (weight[i][j] > 0 && weight[i][j] < inf) obj[i]++;
		}
	}
	//열기준
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (weight[i][j] > 0 && weight[i][j] < inf) obj[j]++;
		}
	}
	//물건 개수
	for (int i = 1; i <= n; i++) cout << n-1-obj[i] << "\n";
}
//플로이드
void Floyd() {
	for (int k = 1; k <= n; k++) {//경유 지점
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);//경유지점을 거치는가?
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();//초기화
	input();//입력
	Floyd();//플로이드
	CountObj();//물건 개수 세기
	return 0;
}
