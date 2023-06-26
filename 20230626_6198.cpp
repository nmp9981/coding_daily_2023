#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int n;
const int maxi = 80001;
ll height[maxi];//높이
stack<ll> s;

//정원꾸미기
void Garden() {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            if (s.top() > height[i]) break;
            s.pop();
        }
        ans += s.size();
        s.push(height[i]);
    }
    cout << ans;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Garden();//정원
    return 0;
}
