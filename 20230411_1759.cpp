#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
vector<char> alpha;
char vowel[5] = { 'a','e','i','o','u' };

//입력
void input() {
    cin >> l >> c;
    for (int k = 0; k < c; k++) {
        char s;
        cin >> s;
        alpha.push_back(s);
    }
    sort(alpha.begin(), alpha.end());//정렬
}
//가능한 암호인가?
bool isPossible(string s) {
    int vowelCnt = 0;//모음 개수
    for (int k = 0; k < s.size(); k++) {
        for (int j = 0 ; j < 5; j++) {
            if (s[k] == vowel[j]) {
                vowelCnt++;//모음
                break;
            }
        }
    }
    //자음, 모음 개수 검사
    if (vowelCnt >= 1 && s.size() - vowelCnt >= 2) return true;
    return false;
}
//암호
void Password(int idx,int cnt,string s) {
    //암호 완성
    if (cnt == l) {
        if (isPossible(s)) cout << s << "\n";
        return;
    }
    for (int i = idx; i < alpha.size(); i++) {
        string next = s + alpha[i];
        Password(i + 1, cnt + 1, next);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Password(0,0,"");//암호
    return 0;
}
