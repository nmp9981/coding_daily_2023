#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
const ll inf = 2100000000;
const int maxi = 1000001;
ll tree[maxi];//나무
//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < n; i++) cin >> tree[i];
}
//나무 길이
ll GetTree(ll x) {
    ll len = 0;
    for (int i = 0; i < n; i++) len += max(0,(tree[i] - x));
    return len;
}
//나무자르기
void CutTree() {
    ll left = 0;
    ll right = inf;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (GetTree(mid) >= m) left = mid + 1;
        else right = mid - 1;
    }
    cout << right;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CutTree();//나무 자르기
    return 0;
}
