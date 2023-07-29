#include <iostream>
using namespace std;

int n,m;
int channelCount;
bool isBreak[10] = { false, };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        isBreak[k] = true;
    }
    channelCount = abs(100 - n);//처음 횟수
}
//조작
void controll(int cnt,int num) {
    if (cnt >= 1) channelCount = min(channelCount, cnt + abs(n - num));
    if (cnt >= 6) return;
    //다음 숫자
    for (int i = 0; i < 10; i++) {
        if (isBreak[i]) continue;//고장난 버튼
        int next = num * 10 + i;
        controll(cnt + 1, next);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    controll(0,0);//조작
    cout << channelCount;//출력
    return 0;
}
