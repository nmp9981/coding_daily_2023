#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n,atk;

//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}
//min
inline ll min(ll x, ll y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>atk;
}
//던전 공략
void Dungeon() {
    ll maxHP = 0;//최대 HP
    ll decreaceHP = 0;//감소한 HP
    for (int i = 0; i < n; i++) {
        ll t, a, h;
        cin >> t >> a >> h;

        if (t == 1) {//사냥
            ll attackCount = (h - 1) / atk;//공격 횟수
            decreaceHP += a*attackCount;//감소량
            maxHP = max(maxHP,decreaceHP);
        }
        else if (t == 2) {//포션
            atk += a;//공격력 증가
            decreaceHP = max(decreaceHP - h, 0ll);//회복
        }
    }
    cout << maxHP + 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Dungeon();//던전공략
    return 0;
}
