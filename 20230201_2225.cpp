#include <iostream>
#include <queue>
using namespace std;

int n, k;
const int maxi = 401;
const int mod = 1000000000;
int dp[maxi][maxi];

//입력
void input() {
    cin >> n>>k;
}
//경우의 수 구하기
void nCr() {
    dp[1][1] = 1; dp[1][0] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%mod;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    nCr();//이동
    cout << dp[k + n - 1][n];//nHk
    return 0;
}
