#include <iostream>
using namespace std;

int n;
const int maxi = 10001;
int grape[maxi];//포도주
int dp[maxi];

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> grape[i];
}
//포도주 마시기
void Drink() {
    dp[0] = grape[0];
    dp[1] = grape[0] + grape[1];
    dp[2] = max(dp[1],max( grape[2] + grape[1], grape[2] + grape[0]));
    for (int i = 3; i < n; i++) {
        dp[i] = max(max(grape[i] + dp[i - 2], grape[i] + grape[i - 1] + dp[i - 3]),dp[i-1]);
    }
    cout << dp[n - 1];//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Drink();//포도주 마시기
    return 0;
}
