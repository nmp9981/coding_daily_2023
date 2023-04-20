#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
const int maxi = 51;
string teach[maxi];//가르치는 글자
bool isTeach[26];//가르친 알파벳
int maxRead = 0;//최대 읽을 수 있는 글자 수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> teach[i];

    //꼭 배워야하는 알파벳
    isTeach[0] = true;
    isTeach[2] = true;
    isTeach[8] = true;
    isTeach[13] = true;
    isTeach[19] = true;
}
//읽기
int Read() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool isStudy = true;//학습 가능한가?
        for (int j = 4; j < teach[i].size()-4; j++) {//양끝 4자리 제외
            char c = teach[i][j];
            if (isTeach[c - 'a'] == false) {
                isStudy = false;
                continue;//안배운 알파벳
            }
        }
        if (isStudy == true) cnt++;
    }
    return cnt;
}
//알파벳 배우기
void SelectAlpha(int idx,int cnt) {
    //k개
    if (cnt == k - 5) {
        maxRead = max(maxRead,Read());
        return;
    }
    //알파벳 선택
    for (int i = idx; i < 26; i++) {
        if (isTeach[i]) continue;//이미 가르침
        
        isTeach[i] = true;
        SelectAlpha(i + 1, cnt + 1);//재귀
        isTeach[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (k < 5) cout << 0;//읽기 불가
    else {
        SelectAlpha(1,0);//알파벳 배우기
        cout << maxRead;//출력
    }
    return 0;
}
