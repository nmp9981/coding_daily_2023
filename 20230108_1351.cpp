#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll n,p,q;
map<ll, ll> m;

ll A(ll x) {
    if (m.count(x)!=0) return m[x];//이미 값 존재
    return m[x] = A(x / p) + A(x / q);
}
//입력
void input() {
    cin >> n >> p >> q;
    m.insert({ 0,1 });
}

int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    cout<<A(n);//수열
    return 0;
}
