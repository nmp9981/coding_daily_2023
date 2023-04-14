#include <iostream>
using namespace std;

int n,m;
const int maxi = 101;
int maxCost = 0;//최대 비용
int memory[maxi];//메모리 양
int cost[maxi];//비용
int dp[maxi][10001];//i번 앱까지의 비활성화 메모리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> memory[i];
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        maxCost += cost[i];
    }
}
//앱 활성화
void AppActive() {
    //메모리 할당
    for (int i = 1; i <= n; i++) {//앱 번호
        for (int j = 0; j <= maxCost; j++) {//현재 비용
            if (j >= cost[i]) {//비용이 충분
                dp[i][j] = max(dp[i - 1][j], memory[i] + dp[i - 1][j - cost[i]]);
            }
            else dp[i][j] = dp[i - 1][j];//비용이 부족
        }
    }
    //비활성화 최소 비용
    for (int j = 0; j <= maxCost; j++) {
        if (dp[n][j] >= m) {
            cout << j;
            break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    AppActive();//앱 활성화
    return 0;
}
