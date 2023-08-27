#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 101;
const int mod = 1000000000;
int dp[maxi][10];

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
}
//계단 수
void StairNumber() {
    for (int j = 1; j < 10; j++) dp[1][j] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][1];
            else if (j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%mod;
        }
    }
    int total = 0;
    for (int j = 0; j < 10; j++) {
        total += dp[n][j];
        total %= mod;
    }
    cout << total % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    StairNumber();//계단수
    return 0;
}
