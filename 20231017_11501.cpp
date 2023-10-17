#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int t,n;
vector<ll> money;//가격
//8방 탐색
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

//입력
void input() {
    money.clear();//초기화
    cin >>n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        money.push_back(x);
    }
}
//주식
void Stock() {
    ll maxMoney = money[money.size() - 1];
    ll total = 0;
    for (int i = money.size() - 2; i >= 0; i--) {
        if (money[i] < maxMoney) total += (maxMoney - money[i]);
        else maxMoney = money[i];
    }
    cout << total << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        input();//입력
        Stock();//주식
    }
    return 0;
}
