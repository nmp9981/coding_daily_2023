#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lecture;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, s, e;
        cin >> num >> s >> e;
        lecture.push_back({ s,e });
    }
    sort(lecture.begin(), lecture.end());//시작시간 기준으로 정렬
}
//강의실
void Classroom() {
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lecture[0].second);

    for (int i = 1; i < n; i++) {
        int startTime = lecture[i].first;
        int endTime = lecture[i].second;

        if (startTime < pq.top()) {
            pq.push(endTime);
            cnt = max(cnt,pq.size());
        }
        else {
            pq.pop();
            pq.push(endTime);
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Classroom();//강의실
    return 0;
}
