#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> ramen;//기한, 보상

//입력
void input() {
    cin >>n;
    for (int i = 0; i < n; i++) {
        int dead, reward;
        cin >> dead >> reward;
        ramen.push_back({ dead,reward });
    }
    sort(ramen.begin(), ramen.end());//기한 순으로 정렬
}
//문제 풀이
void Solve() {
    priority_queue<int,vector<int>,greater<int>> homework;//숙제
    for (int i = 0; i < n; i++) {
        homework.push(ramen[i].second);//숙제
        if (homework.size() > ramen[i].first) homework.pop();
    }
    int sum = 0;
    while (!homework.empty()) {
        sum += homework.top();
        homework.pop();
    }
    cout << sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Solve();//문제 풀이
    return 0;
}
