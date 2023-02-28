#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 101;
int A[maxi];//수열
ll dp[maxi][21];//i번까지 했을때 결과가 j인 경우의 수 

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	dp[0][A[0]] = 1;//맨 처음
}
//덧셈
void Equals() {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i-1][j] == 0) continue;//이전값이 없는 경우
			if (j + A[i] <= 20) dp[i][j + A[i]] += dp[i - 1][j];
			if (j - A[i] >= 0) dp[i][j - A[i]] += dp[i - 1][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Equals();//덧셈
	cout << dp[n-2][A[n-1]];
	return 0;
}
