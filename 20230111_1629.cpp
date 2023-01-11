#include <iostream>
using namespace std;
typedef long long ll;

ll a,b,c;

//입력
void input() {
	cin >> a>>b>>c;
}
//곱셈
ll mul(ll x, ll y, ll mod) {
	if (y == 1) return x%mod;

	ll p = mul(x, y / 2, mod) % mod;
	if (y % 2 == 0) {
		return (p * p) % mod;
	}
	else {
		return (((p * p)%mod) * x) % mod;
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
  input();//입력
	cout<<mul(a,b,c);//곱셈
	return 0;
}
