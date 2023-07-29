#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
vector<char> alpha;
vector<char> password;
char vowel[5] = { 'a','e','i','o','u'};//모음

//입력
void input() {
    cin>>l>>c;
    for (int i = 0; i < c; i++) {
        char h; cin >> h;
        alpha.push_back(h);
    }
    sort(alpha.begin(), alpha.end());//사전순
}
//모음 조건
bool isVowel(vector<char> word) {
    int vowelCnt = 0;
    for (char a : word) {
        for (int i = 0; i < 5; i++) {
            if (vowel[i] == a) {
                vowelCnt++;
                break;
            }
        }
    }
    if (vowelCnt >= 1 && l - vowelCnt >= 2) return true;
    return false;
}
//암호만들기
void MakePassword(int idx,int cnt) {
    if (cnt == l) {
        //조건 만족
        if (isVowel(password)) {
            for (char ch : password) cout << ch;
            cout << "\n";
        }
        return;
    }
    //다음 문자
    for (int i = idx; i < c; i++) {
        password.push_back(alpha[i]);
        MakePassword(i + 1, cnt + 1);
        password.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MakePassword(0,0);//암호 만들기
    return 0;
}
