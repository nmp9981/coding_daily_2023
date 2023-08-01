#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> ramen;

//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ramen.push_back({ a,b });
    }
    sort(ramen.begin(), ramen.end());//데드라인 순으로 정렬
}
//식사
void Eat() {
    int total = 0;
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙
    for (int i = 0; i < n; i++) {
        int deadLine = ramen[i].first;
        int reward = ramen[i].second;

        pq.push(reward);
        if (pq.size() > deadLine) pq.pop();
    }
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
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
