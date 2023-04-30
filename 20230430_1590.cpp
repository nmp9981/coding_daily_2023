#include <iostream>
#include <vector>
using namespace std;

struct BusInfo {
    int start, interval, cnt;//시작, 간격, 대수
};
int n,t,s,k,c;
const int inf = 100000000;
int waitTime = inf;//대기 시간
vector<BusInfo> bus;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n>>t;
    for (int i = 1; i <= n; i++) {
        cin >> s >> k >> c;
        bus.push_back({ s,k,c });
    }
}
//버스
void Bus() {
    for (int i = 0; i < bus.size(); i++) {//각 버스에 대해
        for (int j = 0; j < bus[i].cnt; j++) {
            int arrive = bus[i].start + j * bus[i].interval;//도착 시간
            if (t <= arrive) waitTime = min(waitTime, arrive - t);
        }
    }
    if (waitTime >= inf) cout << -1;
    else cout << waitTime;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Bus();//버스
    return 0;
}
