#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll n,p,q;
map<ll,ll> m;

//입력
void input() {
    cin >> n>>p>>q;
    m[0] = 1;
}
//dp
ll F(ll x) {
    if (x == 0) return 1;
    if (m[x] >0) return m[x];

    return m[x] = F(x / p) + F(x / q);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<F(n);
    return 0;
}
