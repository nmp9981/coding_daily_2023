#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> lecture;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, st, ed;
        cin >> num >> st >> ed;
        lecture.push_back({ st,ed });
    }
    sort(lecture.begin(), lecture.end());//시작 시간 기준 정렬
}
//강의 배정
void ClassRoom() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lecture[0].second);
    int room = 1;

    for (int i = 1; i < lecture.size(); i++) {
        int nextStart = lecture[i].first;//다음 강의 시작시간
        int endTime = pq.top();//가장 빨리 끝나는 강의시간

        if (nextStart < endTime) room++;//방을 늘려야함
        else pq.pop();//방 교체
        pq.push(lecture[i].second);
    }
    cout << room;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ClassRoom();//강의 배정
    return 0;
}
