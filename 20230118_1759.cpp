#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
const int maxi = 31;
vector<char> vowel = {'a','e','i','o','u'};
vector<char> word;//단어
int tile[maxi];//타일을 놓는 경우의 수

//모음 판별
bool isVowel(char w) {
    for (int j = 0; j < 5; j++) {
        if (w == vowel[j]) return true;
    }
    return false;
}
//입력
void input() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char s; cin >> s;
        word.push_back(s);
    }
    sort(word.begin(),word.end());//정렬
}
//암호 구하기
void Password(int idx,int con,int vow,string pw) {//총 개수, 자음개수, 모음 개수, 문자열
    //모두 채움
    if (con+vow == l) {
        //자모음 조건 만족
        if (con >= 2 && vow >= 1) cout << pw << "\n";
        return;
    }
    //다음 단어
    for (int i = idx; i < c; i++) {
        if (isVowel(word[i])) Password(i + 1, con, vow + 1, pw + word[i]);//자음
        else Password(i + 1, con + 1, vow, pw + word[i]);//모음
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Password(0,0,0,"");//암호 나열
    return 0;
}
