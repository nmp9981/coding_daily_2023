#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int n;
const int maxi = 80001;
ll height[maxi];//높이
stack<ll> s;//스택

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];
}
//빌딩
void Building() {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        //더 큰건물 올때까지 
        while (!s.empty()) {
            if (s.top() > height[i]) break;
            s.pop();
        }
        cnt += s.size();
        s.push(height[i]);
    }
    cout << cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Building();//빌딩
    return 0;
}
