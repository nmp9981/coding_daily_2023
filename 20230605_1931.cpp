#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> conference;//종료 , 시작

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        conference.push_back({ b,a });//종료, 시작
    }
    sort(conference.begin(), conference.end());//종료시각 기준으로 정렬
}
//회의
void Meeting() {
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙
    pq.push(conference[0].first);

    for (int i = 1; i < n; i++) {
        int startTime = conference[i].second;
        int endTime = conference[i].first;

        if (pq.top() <= startTime) {//회의 추가
            pq.push(endTime);
            pq.pop();
            cnt++;
        }
    }
    cout << cnt;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Meeting();//회의
    return 0;
}
