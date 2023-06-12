#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> schedules;//시간표

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        schedules.push_back({ s,t });
    }
    sort(schedules.begin(), schedules.end());//시작 시간순으로 정렬
}
//강의실
void ClassRoom() {
    int cnt = 1;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(schedules[0].second);

    for (int i = 1; i < schedules.size(); i++) {
        if (schedules[i].first < pq.top()) cnt++;// 종료시각보다 더 일찍 시작
        else pq.pop();
        pq.push(schedules[i].second);
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ClassRoom();//강의실
    return 0;
}
