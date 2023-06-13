#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
const int maxi = 101;
int A[maxi];//수열
ll dp[21][maxi];//결과가 i, 길이 j인 식의 개수

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    memset(dp, - 1, sizeof(dp));//초기화
}

//식의 개수
ll Equals(int idx,int res) {
    if (res < 0 || res > 20) return 0;//범위 초과
    if (dp[res][idx] != -1) return dp[res][idx];//이미 계산
    //마지막 숫자
    if (idx == n - 1) {
        if (res == A[n-1]) return dp[res][idx] = 1;
        else return dp[res][idx] = 0;
    }

    ll cnt = 0;
    cnt += Equals(idx + 1, res + A[idx]);
    cnt += Equals(idx + 1, res - A[idx]);//덧셈과 뺄셈
    dp[res][idx] = cnt;
    return dp[res][idx];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Equals(1,A[0]);//식의 개수
    return 0;
}
