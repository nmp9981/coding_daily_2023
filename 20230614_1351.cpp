#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll n,p,q;
map<ll, ll> m;

//입력
void input() {
    cin >> n>>p>>q;
}
// 무한 수열
ll A(ll x) {
    if (x == 0) return 1;//0
    if (m[x] != 0) return m[x];//이미 존재

    return m[x] = A(x / p) + A(x / q);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<A(n);//무한 수열
    return 0;
}
