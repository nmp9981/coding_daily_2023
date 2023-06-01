#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> ramen;//기한, 보상
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int day, reward;
        cin >> day >> reward;
        ramen.push_back({ day,reward });
    }
    sort(ramen.begin(), ramen.end());//기한 순으로 정렬
}
void Eat() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < ramen.size(); i++) {
        int deadline = ramen[i].first;
        int reward = ramen[i].second;

        pq.push(reward);
        if (deadline < pq.size()) pq.pop();
    }
    int total = 0;
    //남은 것 더하기
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }
    cout << total;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Eat();//라면 먹기
    return 0;
}
