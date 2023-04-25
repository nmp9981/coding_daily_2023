#include <iostream>
#include <cmath>
using namespace std;

int n,m;
const int maxi = 10;
bool breakChannel[maxi];//고장난 채널
int ans;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        breakChannel[c] = true;//고장난 채널
    }
    ans = abs(n - 100);//+,-만 눌렀을 경우
}
//버튼
void Button(int ch,int cnt) {
    if (cnt >= 1) ans = min(ans, cnt + abs(ch - n));//총 누르는 횟수
    if (cnt >= 6) return;//범위 초과

    //다음 숫자
    for (int i = 0; i < maxi; i++) {
        if (breakChannel[i]) continue;//고장난 채널
        int next = ch * 10 + i;//다음 채널
        Button(next, cnt + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Button(0,0);//버튼
    cout << ans;//출력
    return 0;
}
