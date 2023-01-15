#include <iostream>
using namespace std;
typedef long long ll;

ll k, n;
const int maxi = 10001;
ll line[maxi];//랜선 길이
//입력
void input() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> line[i];
}
//랜선 개수 구하기
int lineLen(int x) {
    int cnt = 0;
    for (int i = 0; i < k; i++) cnt += (line[i] / x);
    return cnt;
}
//랜선 길이 구하기
void online() {//크기, 위치
    ll start = 0;
    ll end = 2147483647;
    while (start <= end) {
        ll mid = (start + end) / 2;//랜선 길이
        if (lineLen(mid) >= n) start = mid + 1;
        else end = mid - 1;
    }
    cout << end;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    online();//랜선 길이 구하기
    return 0;
}
