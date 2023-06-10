#include <iostream>
#include <string>
using namespace std;

int n,m;
string s;

//입력
void input() {
    cin >> n >> m;
    cin >> s;
}
//IOI
void IOI() {
    int cnt = 0;
    int num = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I') {
            while (s.substr(i + 1, 2) == "OI") {
                num++;
                i += 2;
                if (num == n) {
                    cnt++;
                    num--;
                }
            }
            num = 0;
        }
    }
    cout <<cnt;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    IOI();//아이오아이
    return 0;
}
