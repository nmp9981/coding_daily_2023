#include <iostream>
using namespace std;

int n;
const int inf = 2147360000;
int ans = -inf;//정답
string modify;//수식

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    cin >> modify;
}
//계산하기
int Cal(int n1, char sign, int n2) {
    int res;
    switch(sign){
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '*':
        res = n1 * n2;
        break;
    case '/':
        res = n1 / n2;
        break;
    }
    return res;
}
//괄호 추가하기
void AddBracket(int idx,int result) {
    //모두 계산
    if (idx > n) {
        ans = max(ans, result);
        return;
    }
    //연산 기호
    char op;
    if (idx == 0) op = '+';
    else op = modify[idx-1];

    //괄호 추가 O (이전에 괄호를 넣지 않았을 경우에만 추가 가능)
    if (idx+2 < n) {
        int calBracket = Cal(modify[idx] - '0', modify[idx + 1], modify[idx + 2] - '0');//괄호 내

        int nextResult = Cal(result,op,calBracket);
        AddBracket(idx + 4, nextResult);
    }
    //괄호 추가 X
    int nextResult = Cal(result, op, modify[idx]-'0');
    AddBracket(idx + 2, nextResult);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    AddBracket(0, 0);//괄호 추가하기
    cout << ans;//출력
    return 0;
}
