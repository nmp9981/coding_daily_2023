#include <string>
#include <vector>
using namespace std;

const int maxi = 60001;
const int mod = 1000000007;
int dp[maxi];

//피보나치 수 구하는 것과 똑같다.
int solution(int n) {
    dp[1] = 1;dp[2] = 2;
    for(int i=3;i<=n;i++) dp[i] = (dp[i-1]+dp[i-2])%mod;
    return dp[n];
}
