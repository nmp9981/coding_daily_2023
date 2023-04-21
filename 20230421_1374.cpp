#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n,num,st,ed;
const int maxi = 100001;
vector<pair<int, int>> classroom;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num >> st >> ed;
        classroom.push_back({ st,ed });
    }
    sort(classroom.begin(), classroom.end());//정렬
}
//강의실 개수
void ClassRoom() {
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(classroom[0].second);
    for (int i = 1; i < n; i++) {
        int startTime = classroom[i].first;
        int endTime = classroom[i].second;

        if (startTime < pq.top()) {//끝난게 없으므로 강의실 추가
            cnt++;
            pq.push(endTime);
        }
        else {//끝난게 있으므로 해당 강의실 사용
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
    ClassRoom();//강의실 개수
    return 0;
}
