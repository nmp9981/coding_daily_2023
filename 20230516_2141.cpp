#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll allpeople = 0;
vector<pair<ll, ll>> village;

//입력
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, a;
        cin >> x >> a;
        village.push_back({ x,a });
        allpeople += a;
    }
    sort(village.begin(), village.end());//위치순 정렬
}
//설치
void Install() {
    ll people = 0;
    for (int i = 0; i < n; i++) {
        people += village[i].second;
        if (people >= ((allpeople+1) / 2)) {
            cout << village[i].first;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    Install();//설치
    return 0;
}
