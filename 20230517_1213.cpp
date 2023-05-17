#include <iostream>
using namespace std;

string name;//이름
string ans = "";//정답
const int maxi = 26;
int alpha[maxi];//각 알파벳 개수

//입력
void Input() {
    cin >> name;
}
//팰린드롬
void Palindrome() {
    for (int i = 0; i < name.size(); i++) alpha[name[i] - 'A']++;
    int odd = 0;//홀수개인 알파벳의 개수
    char middle;//가운데
    for (int i = 0; i < maxi; i++) {
        if (alpha[i] % 2 == 1) {
            odd++;
            middle = char(i + 'A');
        }
    }
    if (odd < 2) {//팰린드롬 가능
        //앞 절반
        for (int i = 0; i < maxi; i++) {
            for (int j = 0; j < alpha[i] / 2; j++) ans += char(i+'A');
        }
        if (odd == 1) ans += middle;//가운데
        //뒤 절반
        for (int i = maxi; i >= 0; i--) {
            for (int j = 0; j < alpha[i] / 2; j++) ans += char(i + 'A');
        }
        cout << ans;
    }
    else cout << "I'm Sorry Hansoo";//팰린드롬 불가
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    Palindrome();//팰린드롬
    return 0;
}
