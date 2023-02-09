#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long ull;

int n;
const int mod = 1000000007;
priority_queue < ull, vector<ull>, greater < ull >> pq;//최소 힙

//입력
void input() {
    //초기화
    while (!pq.empty()) {
        pq.pop();
    }
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        ull a; cin >> a;
        pq.push(a);
    }
}
//합성
void Compose() {
    ull Cost = 1;//비용 총합
    while (true) {
        if (pq.size() == 1) break;

        //에너지 합성
        ull firstE = pq.top(); pq.pop();
        ull secondE = pq.top(); pq.pop();
        ull newE = firstE * secondE;//새로운 에너지
        pq.push(newE);

        newE %= mod;
        Cost *= newE;
        Cost %= mod;
    }
    cout << Cost << "\n";//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        Compose();//합성
    }
    return 0;
}
