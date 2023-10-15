#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n;
vector<pair<ll,ll>> post;
ll total = 0;

//min
inline ll min(ll x, ll y) {
    return x > y ? y : x;
}
//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >>n;
    for (int i = 0; i <n; i++) {
        ll a, b;
        cin >> a >> b;
        post.push_back({ a,b });
        total += b;
    }
    sort(post.begin(),post.end());
}
//우체국 설치
void Install() {
    ll sum = 0;
    for (int i = 0; i < post.size(); i++) {
        ll pos = post[i].first;
        ll people = post[i].second;

        sum += people;
        if (sum >= (total+1) / 2) {
            cout << pos;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Install();//우체국 설치
    return 0;
}
