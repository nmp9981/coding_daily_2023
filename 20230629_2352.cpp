#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 40001;
int port[maxi];//포트 번호

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> port[i];
}
//연결하기
void Connect() {
    vector<int> usePort;
    for (int i = 0; i < n; i++) {
        int curPort = port[i];
        if (usePort.size() == 0 || usePort[usePort.size() - 1] < curPort) usePort.push_back(curPort);
        else {
            int pos = lower_bound(usePort.begin(), usePort.end(), curPort) - usePort.begin();//위치
            usePort[pos] = curPort;
        }
    }
    cout << usePort.size();//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Connect();//연결하기
    return 0;
}
