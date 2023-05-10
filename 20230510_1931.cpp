#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> conference;//회의 시간

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start>>end;
        conference.push_back({ end,start });//끝, 시작
    }
    sort(conference.begin(), conference.end());//끝나는 시간을 기준으로 정렬
}
//회의
void Meeting() {
    int cnt = 1;
    int endTime = conference[0].first;
    for (int i = 1; i < conference.size(); i++) {
        int startTime = conference[i].second;//시작시간
        if (startTime >= endTime) {//시작시간이 종료시간 이후이면
            cnt++;
            endTime = conference[i].first;
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
