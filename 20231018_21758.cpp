#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n;
ll bee1, bee2;
const int maxi = 100001;
ll honey[maxi];//꿀
ll sumHoney[maxi];//꿀 누적양
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> honey[i];
        sumHoney[i] = sumHoney[i - 1] + honey[i];
    }
}
//꿀따기
void GetHoney() {
    ll result[3] = { 0,0,0 };
    //벌 꿀통 벌
    ll maxHoney = 0;
    for (int i = 1; i <= n; i++) {
        maxHoney = max(maxHoney, honey[i]);
    }
    result[0] = sumHoney[n - 1] - honey[1] + maxHoney;

    //벌 벌 꿀통
    for (int i = 2; i < n; i++) {
        bee1 = sumHoney[n] - honey[1] - honey[i];
        bee2 = sumHoney[n] - sumHoney[i];
        result[1] = max(result[1], bee1 + bee2);
    }
    //꿀통 벌 벌
    for (int i = 2; i < n; i++) {
        bee1 = sumHoney[i-1];
        bee2 = sumHoney[n-1] - honey[i];
        result[2] = max(result[2], bee1 + bee2);
    }
    //결과
    cout << max(result[0], max(result[1], result[2]));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    GetHoney();//꿀 따기
    return 0;
}
