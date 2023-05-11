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
        int num, start, end;
        cin >> num >> start >> end;
        lecture.push_back({ start,end });
    }
    sort(lecture.begin(), lecture.end());//시작시간 순으로 정렬
}
//교실
void ClassRoom() {
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;//종료시간(최소 힙)
    pq.push(lecture[0].second);

    for (int i = 1; i < lecture.size(); i++) {
        int startTime = lecture[i].first;
        int endTime = lecture[i].second;
        if (pq.top() > startTime) {
            pq.push(endTime);
            cnt++;
        }
        else {
            pq.pop();
            pq.push(endTime);
        }
    }
    cout << cnt;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ClassRoom();//교실
    return 0;
}
