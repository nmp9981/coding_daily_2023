#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> ramen;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ramen.push_back({ a,b });
    }
    sort(ramen.begin(), ramen.end());//시작시간 순으로 정렬
}
//식사
void Eat() {
    int total = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(ramen[0].second);
    for (int i = 1; i < n; i++) {
        int startTime = ramen[i].first;//종료
        int endTime = ramen[i].second;//시작

        //늘리지X
        if (pq.top() <= startTime) {
            pq.pop();
            pq.push(endTime);
        }
        else {//늘려야함
            pq.push(endTime);
            total = max(total, pq.size());
        }
    }
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Eat();//식사
    return 0;
}
