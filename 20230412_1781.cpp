#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> Task;

//입력
void input() {
    cin >> n;
    for (int k = 0; k < n; k++) {
        int d,r;
        cin >> d>>r;
        Task.push_back({ d,r });
    }
    sort(Task.begin(), Task.end());//정렬
}
//라면 얻기
void GetRamen() {
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙
    for (int i = 0; i < n; i++) {
        int day = Task[i].first;
        int reward = Task[i].second;
        pq.push(reward);

        if (pq.size() > day) pq.pop();
    }
    //총 보상
    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    GetRamen();//라면 얻기
    return 0;
}
