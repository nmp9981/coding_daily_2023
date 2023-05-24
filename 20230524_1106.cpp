#include <iostream>
using namespace std;

int c,n;
const int maxi = 100001;
int cost[21];//비용
int reward[21];//가격
int maxReward[maxi];//i원으로 만들 수 있는 최대 고객 수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> c>>n;
    for (int i = 1; i <= n; i++) cin>>cost[i]>>reward[i];
}
//호텔
void Hotel() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxi; j++) {
            if (cost[i] <= j) maxReward[j] = max(maxReward[j], maxReward[j - cost[i]] + reward[i]);
        }
    }
    //돈의 최솟값
    int money = 0;
    for (int i = 1; i < maxi; i++) {
        if (maxReward[i] >= c) {//최소 손님 만족
            cout << i;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Hotel();//호텔
    return 0;
}
