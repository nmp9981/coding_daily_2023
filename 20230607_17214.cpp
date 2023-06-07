#include <iostream>
#include <string>
using namespace std;

string s;
bool isX = false;//미지수가 있는가?
int xIdx = 0;//x위치

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> s;
}
//적분
void Integral() {
    //1차식인가?
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') {
            xIdx = i;
            isX = true;
        }
    }
    if (isX) {//1차식
        //계수
        if (s.substr(0, xIdx) == "-2") cout << "-xx";
        else if (s.substr(0, xIdx) == "2") cout << "xx";
        else {
            int num = stoi(s.substr(0, xIdx));
            cout << num / 2 << "xx";
        }
        //상수항
        if (s.substr(xIdx + 1) == "-1") cout << "-x+W";
        else if (s.substr(xIdx + 1) == "+1") cout << "+x+W";
        else if (s.substr(xIdx + 1) == "") cout << "+W";
        else cout << s.substr(xIdx + 1) << "x+W";
    }
    else {//상수
        if (s.substr(xIdx) == "-1") cout << "-x+W";
        else if (s.substr(xIdx) == "1") cout << "x+W";
        else if (s.substr(xIdx) == "0") cout << "W";
        else cout << s.substr(xIdx) << "x+W";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Integral();//적분
    return 0;
}
