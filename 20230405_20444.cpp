#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, k;

//입력
void input() {
    cin >> n >> k;
}
//함수
ll F(ll x) {
    return (x + 1)*(n - x + 1);
}
//이분탐색
void LCS() {
    ll left = 0;
    ll right = n / 2;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll fx = F(mid);
        if (fx == k) {
            cout << "YES";
            return;
        }
        else if (fx > k) right = mid-1;
        else if (fx < k) left = mid+1;
    }
    cout << "NO";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LCS();//LCS
    return 0;
}
