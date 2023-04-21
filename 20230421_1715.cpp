#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 100001;
priority_queue<int,vector<int>,greater<int>> pq;//최소힙

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
}
//비교하기
void Compare() {
    int total = 0;
    while (pq.size()>1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();

        int sum = n1 + n2;
        pq.push(sum);
        total += sum;
    }
    cout << total;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Compare();//비교하기
    return 0;
}
