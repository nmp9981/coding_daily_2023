#include <iostream>
using namespace std;

int n, m;
string s;
int cnt = 0;

//입력
void input() {
    cin >> n>>m;
    cin >> s;
}
//IOI문자열 탐색
void IOI() {
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I') {//시작 지점 일치
            int l = 0;
            while (s[i + 1] == 'O' && s[i + 2] == 'I') {//두 문자열 일치
                l++;
                if (l == n) {//충족
                    cnt++;
                    l--;
                }
                i += 2;
            }
            l = 0;//초기화
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    IOI();//IOI문자열 탐색
    return 0;
}
