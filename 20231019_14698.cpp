#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n;
const ll mod = 1000000007;
priority_queue<ll, vector<ll>, greater<ll>> pq;//최소힙
//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
}
//초기화
void Init() {
    while (!pq.empty()) pq.pop();
}
//슬라임
void Slime() {
    ll cost = 1;
    while (pq.size()>1) {
        ll firstCost = pq.top();
        pq.pop();
        ll secondCost = pq.top();
        pq.pop();
        ll newCost = firstCost * secondCost;
        pq.push(newCost);

        newCost = newCost % mod;
        cost = (cost * newCost) % mod;
    }
    cout << cost<<"\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        Init();//초기화
        input();//입력
        Slime();//슬라임
    }
    return 0;
}
