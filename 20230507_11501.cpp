#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
const int maxi = 1000001;
ll cost[maxi];//가격

//입력
void input() {
    memset(cost, 0, sizeof(cost));//초기화
    cin >> n;
    for (int k = 0; k < n; k++) cin >> cost[k];
}
//주식
void Stock() {
    ll money = 0;//이익
    ll sellCost = cost[n - 1];//판매 가격
    for (int i = n-2; i >= 0; i--) {
        if (sellCost >= cost[i]) money += (sellCost - cost[i]);//판매
        else sellCost = cost[i];//판매 가격 갱신
    }
    cout << money << "\n";//결과
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        Stock();//주식
    }
    return 0;
}
