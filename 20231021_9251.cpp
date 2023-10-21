#include <iostream>
using namespace std;

int n;
const int maxi = 1001;
int len[maxi][maxi];//각 문자열 i,j까지의 LCS길이
string a, b;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> a >> b;
    a = '0' + a;
    b = '1' + b;
}

//LCS
void LCS() {
    int aSize = a.size(); int bSize = b.size();
    for (int i = 1; i < aSize; i++) {
        for (int j = 1; j < bSize; j++) {
            if (a[i] == b[j]) {
                len[i][j] = len[i - 1][j - 1] + 1;
            }
            else {
                len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            }
        }
    }
    cout << len[aSize - 1][bSize - 1]<<"\n";//LCS 길이
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LCS();//LCS
    return 0;
}
