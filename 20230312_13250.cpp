#include <iostream>
using namespace std;

int n;
const int maxi = 1000001;
double dp[maxi];//i이상 나올때 기댓값

//입력
void input() {
	cin >> n;
}
//초기 값
void init() {
	dp[1] = 1.0;
	dp[2] = 1+ dp[1] / 6;
	dp[3] = 1+(dp[2] + dp[1]) / 6;
	dp[4] = 1+(dp[3] + dp[2] + dp[1]) / 6;
	dp[5] = 1+(dp[4] + dp[3] + dp[2] + dp[1]) / 6;
	dp[6] = 1+(dp[5] + dp[4] + dp[3] + dp[2] + dp[1])/6;
}
//주사위
void Dice() {
	for (int i = 7; i <= n; i++) {
		dp[i] = 1+(dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) / 6;
	}
	printf("%.9lf", dp[n]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	init();//초기화
	Dice();//주사위
	return 0;
}
