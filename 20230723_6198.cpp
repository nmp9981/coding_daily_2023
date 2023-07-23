#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int n;
const int maxi = 100001;
int A[maxi];//수열

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//정원꾸미기
void Garden() {
    stack<ll> s;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        //더 큰건물 올때까지
        while (!s.empty()) {
            if (s.top() > A[i]) break;
            s.pop();
        }
        cnt += s.size();
        s.push(A[i]);
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
