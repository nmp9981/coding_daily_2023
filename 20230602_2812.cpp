#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n,k;
string number;
stack<int> s;

//입력
void input() {
    cin >> n >> k;
    cin >> number;
}
//크게 만들기
void MakeBig() {
    s.push(number[0] - '0');
    for (int i = 1; i < n; i++) {
        int newN = number[i] - '0';
        while (!s.empty() && k>0) {
            if (s.top() < newN) {//더 큰수
                s.pop();
                k--;
            }
            else break;
        }
        s.push(newN);
    }
    while (k--) s.pop();//마저 지우기

    //정답 출력
    string ans = "";
    while (!s.empty()) {
        ans += to_string(s.top());
        s.pop();
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MakeBig();//크게 만들기
    return 0;
}
