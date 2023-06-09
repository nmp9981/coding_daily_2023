#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
const int mod = 9901;
int dp[maxi][3];//경우의 수

//입력
void input() {
    cin >> n;
}
//동물원
void Zoo() {
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0]+dp[i-1][1]+dp[i-1][2])%mod;//배치x
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][0])%mod;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][0])%mod;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2])%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Zoo();//동물원
    return 0;
}
