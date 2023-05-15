#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
const int maxi = 1000001;
ll cost[maxi];//가격

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    memset(cost, 0, sizeof(cost));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];
}
//주식
void Stock() {
    ll profit = 0;//이익
    ll sellPrice = cost[n-1];//판매가
    for (int i = n - 2; i >= 0; i--) {
        if (sellPrice > cost[i]) profit += (sellPrice - cost[i]);//판매
        else sellPrice = cost[i];
    }
    cout << profit<<"\n";//출력
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
