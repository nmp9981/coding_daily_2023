#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct DungeonInfo {
    int Type, Attack, HP;
};
ll n, heroAttack;
vector<DungeonInfo> Dungeon;

//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>heroAttack;
}
//사냥
void Hunting() {
    ll minHP = 0;//필요한 최소 HP
    ll damage = 0;//입은 데미지
    for (int i = 0; i < n; i++) {
        ll type, attack, HP;
        cin >> type >> attack >> HP;
        if (type == 1) {//사냥
            ll attackCount = (HP-1) / heroAttack;
            damage += (attackCount * attack);
            minHP = max(minHP, damage);//최대 HP를 저장해준다. 마지막이 회족일 경우 영향을 받지 않기 위함
        }
        else if (type == 2) {//회복
            heroAttack += attack;
            damage = max(0,damage-HP);
        }
    }
    cout << minHP+1;//피1부턴 안죽음
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Hunting();//사냥
    return 0;
}
