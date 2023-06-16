#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
const int maxi = 101;
int A[maxi];//수열
ll dp[21][maxi];//j번까지 했을때의 결과

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    memset(dp, -1, sizeof(dp));//초기화
}
//등식의 개수
ll Equals(int res, int idx) {
    if (res < 0 || res>20) return 0;//범위 초과
    if (dp[res][idx] != -1) return dp[res][idx];//이미 존재
    if (idx == n) {
        if (res == A[n]) return dp[res][idx] = 1;
        else return dp[res][idx] = 0;
    }

    dp[res][idx] = Equals(res+A[idx],idx+1) + Equals(res-A[idx],idx+1);
    return dp[res][idx];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Equals(A[1],2);//등식
    return 0;
}
