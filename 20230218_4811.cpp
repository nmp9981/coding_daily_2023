#include<iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 31;
ll dp[maxi][maxi];//알약 경우의 수

//초기화
void init() {
	for (int i = 0; i < maxi; i++) dp[0][i] = 1;
	dp[1][0] = 1;
}
//알약
ll Pill(int x,int y) {
	if (dp[x][y]!=0) return dp[x][y];
	if (x < 0 || x >= maxi || y < 0 || y >= maxi) return 0;
	return dp[x][y] = Pill(x - 1, y + 1) + Pill(x, y - 1);//정상+절반
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();//초기화
	Pill(29,1);//알약

	while (true) {
		cin >> n;
		if (n == 0) break;

		cout << dp[n-1][1] << "\n";
	}
	return 0;
}
