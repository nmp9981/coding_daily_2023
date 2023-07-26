#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> conference;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        conference.push_back({ b,a });//종료,시작
    }
    sort(conference.begin(), conference.end());//정렬
}
//회의실
void Meeting() {
    int cnt = 1;
    int endTime = conference[0].first;
    for (int i = 1; i < n; i++) {
        //종료시각 이후
        if (conference[i].second >= endTime) {
            cnt++;
            endTime = conference[i].first;
        }
    }
    cout << cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Meeting();//회의실
    return 0;
}
