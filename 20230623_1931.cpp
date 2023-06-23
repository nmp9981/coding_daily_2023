#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> schedules;//스케줄

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        schedules.push_back({ ed,st });//종료, 시작
    }
    sort(schedules.begin(), schedules.end());//종료시각 기준으로 정렬
}
//회의
void Conference() {
    int cnt = 1;
    int closedTime = schedules[0].first;

    for (int i = 1; i < n; i++) {
        int open = schedules[i].second;
        int closed = schedules[i].first;
        if (open >= closedTime) {//기존 종료 시각 이후에 개최
            cnt++;
            closedTime = closed;
        }
    }
    cout << cnt;
}
int main() {
    input();//입력
    Conference();//회의
    return 0;
}
