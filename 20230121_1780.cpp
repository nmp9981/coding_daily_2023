#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> homework;//숙제

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int due, xp;
        cin >> due >> xp;
        homework.push_back({ due,xp });
    }
    sort(homework.begin(), homework.end());
}
//컵라면 개수 구하기
void CupRamen() {
    priority_queue<int,vector<int>,greater<int>> pq;//최소힙
    for (int i = 0; i < n; i++) {
        int day = homework[i].first;//기한
        int reward = homework[i].second;//보상
        pq.push(reward);

        if (pq.size() > day) {//용량 초과
            pq.pop();//가장 작은 값을 제거
        }
    }
    int total = 0;
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }
    cout << total;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    CupRamen();//컵라면 개수 구하기
    return 0;
}
