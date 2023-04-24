#include <iostream>
using namespace std;

int n,k;
const int maxi = 100001;
int weight[maxi];//무게
int value[maxi];//가치
int dp[101][maxi];//i번 물건까지 j무게일때의 가치의 최댓값

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
}
//배낭
void Bag() {
    //맨 윗줄
    for (int j = 0; j <= k; j++) {
        if (j >= weight[0]) dp[0][j] = value[0];
    }
    //냅색 알고리즘
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];//무게 부족
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[n-1][k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Bag();//배낭
    return 0;
}
