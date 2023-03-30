#include <iostream>
using namespace std;

int n,m;
const int maxi = 41;
int dp[maxi][maxi];

//입력
void input() {
    cin >> n>>m;
    cout << dp[m-1][m-n];
}
//nCr
void nCr() {
    dp[1][0] = 1; dp[1][1] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == n) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    nCr();//조합
    input();//입력
    return 0;
}
