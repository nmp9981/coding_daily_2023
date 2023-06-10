#include <iostream>
#include <string>
using namespace std;

string s;
const int maxi = 5001;
const int mod = 1000000;
int code[maxi];//i자기가지의 가짓수

//입력
void input() {
    cin >> s;
    s = " " + s;//공백 추가
}
//암호 코드
void Password() {
    //처음 2개
    code[0] = 1;
    if (s[1] - '0' == 0) {
        cout << 0;
        return;
    }
    else code[1] = 1;

    //다음 자리부터
    for (int i = 2; i < s.size(); i++) {
        int num = stoi(s.substr(i - 1, 2));
        if (s[i] - '0' == 0) {
            if (num == 10 || num == 20) code[i] = code[i - 2];//j,t
            else {
                cout << 0;
                return;
            }
        }
        else {
            if (s[i-1]-'0'!=0) {//이전 알파벳
                if (num > 26) code[i] = code[i - 1];
                else code[i] = (code[i - 1] + code[i - 2])%mod;
            }
            else code[i] = code[i - 1];
        }
    }
    cout << code[s.size()-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Password();//암호 코드
    return 0;
}
