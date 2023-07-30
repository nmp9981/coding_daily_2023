#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
const int maxi = 1001;
int times[maxi][maxi];//최소 시간

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
    memset(times, -1, sizeof(times));
}
//조작
void controll() {
    queue<pair<pair<int, int>,int>> q;
    q.push({ {1,0 },0 });//화면, 저장, 시간
    times[1][0] = 0;

    while (!q.empty()) {
        int screen = q.front().first.first;
        int store = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        //완료
        if (screen == n) {
            cout << cnt;
            return;
        }

        //복사
        if (times[screen][screen] == -1) {
            times[screen][screen] = times[screen][store] + 1;
            q.push({ {screen,screen},cnt + 1 });
        }
        //붙여넣기
        if (store+screen < maxi && times[screen + store][store] == -1) {
            times[screen + store][store] = cnt + 1;
            q.push({ { screen + store,store },cnt + 1});
        }
        //삭제
        if (screen > 0 && times[screen - 1][store] == -1) {
            times[screen - 1][store] = cnt + 1;
            q.push({ { screen - 1,store },cnt + 1 });
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    controll();//이모티콘
    return 0;
}
