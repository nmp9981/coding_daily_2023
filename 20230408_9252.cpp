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

//입력
void input() {
    cin >> a >> b;
    a = '0' + a;
    b = '1' + b;
}
//LCS
void LCS() {
    int aSize = a.size()-1; int bSize = b.size()-1;
    for (int i = 1; i <= aSize; i++) {
        for (int j = 1; j <= bSize; j++) {
            if (a[i] == b[j]) len[i][j] = len[i - 1][j - 1] + 1;
            else len[i][j] = max(len[i - 1][j], len[i][j - 1]);
        }
    }
    cout << len[aSize][bSize]<<"\n";//LCS 길이
}
//끝에서부터 추적
void Trace() {
    string ans;
    int x = a.size() - 1; int y = b.size() - 1;
    while (x > 0 && y > 0) {
        if (a[x] == b[y]) {//문자열이 같다.
            ans += a[x];
            x--;
            y--;
        }
        else {//다르면 최대인 쪽으로
            if (len[x - 1][y] < len[x][y - 1]) y--;
            else x--;
        }
    }
    //출력
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LCS();//LCS
    Trace();//추적
    return 0;
}
