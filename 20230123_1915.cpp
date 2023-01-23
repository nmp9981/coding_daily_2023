#include <iostream>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

int n,m;
const int maxi = 1001;
int square[maxi][maxi];//정사각형
int len[maxi][maxi];//최대 길이
int maxLen = 0;//최대 길이

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//min
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &square[i][j]);
            len[i][j] = square[i][j];
        }
    }
}
//넓이 구하기
void Area() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (square[i][j] == 1) {
                len[i][j] = 1 + min(len[i - 1][j], min(len[i][j - 1], len[i - 1][j - 1]));
                maxLen = max(len[i][j], maxLen);
            }
        }
    }
    cout << maxLen * maxLen;
}
int main() {
    //빠른 입력
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    input();//입력
    Area();//넓이 구하기
    return 0;
}
