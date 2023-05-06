#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> schedule;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int start, end;//종료, 시작
        cin >> start >> end;
        schedule.push_back({ end,start });
    }
    sort(schedule.begin(), schedule.end());//종료시각 기준으로 정렬
}

//회의
void Meeting() {
    int cnt = 1;
    int endTime = schedule[0].first;

    for (int i = 1; i < n; i++) {
        //최종 종료시각 <= 시작시각
        if (endTime <= schedule[i].second) {
            cnt++;
            endTime = schedule[i].first;
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Meeting();//미팅
    return 0;
}
