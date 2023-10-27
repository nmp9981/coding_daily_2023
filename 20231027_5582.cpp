#include <iostream>
using namespace std;

string a, b;
int maxLen = 0;
int aSize, bSize;
const int maxi = 4001;
int dp[maxi][maxi];//LCS길이
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >>a >> b;
}
//초기화
void Init() {
    aSize = a.size();
    bSize = b.size();
    for (int i = 0; i < aSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (a[i] == b[j]) dp[i][j] = 1;
        }
    }
}
//공통 부분 문자열
void LCS() {
    for (int i = 1; i < aSize; i++) {
        for (int j = 1; j < bSize; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    cout << maxLen;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Init();//초기화
    LCS();//공통 부분 문자열
    return 0;
}
