#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> lecture;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, st, ed;
        cin >> num >> st >> ed;
        lecture.push_back({ st,ed });
    }
    sort(lecture.begin(), lecture.end());
}

//강의실
void Classroom() {
    int room = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lecture[0].second);

    for (int i = 1; i < n; i++) {
        int nextStart = lecture[i].first;
        int endTime = pq.top();

        if (endTime > nextStart) {
            room++;
            pq.push(lecture[i].second);
        }
        else {
            pq.pop();
            pq.push(lecture[i].second);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Classroom();//강의실
    return 0;
}
