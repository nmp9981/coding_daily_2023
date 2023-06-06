#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll total = 0;
vector<pair<ll,ll>> post;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        post.push_back({ a,b });
        total += b;
    }
    sort(post.begin(), post.end());//위치 기준 정렬
}
//우체국 설치
void Install() {
    ll csum = 0;;
    for (int i = 0; i < n; i++) {
        ll pos = post[i].first;
        ll people = post[i].second;

        csum += people;
        if (csum >= ((total+1) / 2)) {
            cout << pos;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Install();//우체국 설치
    return 0;
}
