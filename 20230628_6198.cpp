#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int n;
stack<ll> s;
const int maxi = 80001;
ll height[maxi];//높이

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> height[i];
}

//정원 꾸미기
void Garden() {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            if (s.top() > height[i]) break;//더 높은 빌딩이 나올때까지
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
    Garden();//정원 꾸미기
    return 0;
}
