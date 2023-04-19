#include <iostream>
using namespace std;
typedef long long ll;

ll n;
const int maxi = 5001;
const ll mod = 1000000007;
ll dp[maxi];//문자열 길이가 i일때 올바른 문자열 개수

//괄호 문자열
void Parenthesis() {
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    for (int i = 6; i < maxi; i += 2) {
        for (int j = 0; j <= i - 2; j += 2) {
            dp[i] += (dp[j] * dp[i - j-2]);//int 범위 초과
            dp[i] %= mod;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Parenthesis();//괄호 문자열

    int t; cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 1) cout << 0 << "\n";
        else cout << dp[n] << "\n";
    }
    return 0;
}
