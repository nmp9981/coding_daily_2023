#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n,k;
string num;
stack<int> s;

//입력
void input() {
    cin >> n>>k;
    cin >> num;
}

//큰 수
void BigNum() {
    s.push(num[0]-'0');
    for (int i = 1; i < n; i++) {
        int newN = num[i] - '0';
        while (!s.empty() && k > 0) {//횟수가 남아있고 스택에 원소가 있는 동안
            if (newN > s.top()) {//더 큰수
                s.pop();
                k--;
            }
            else break;
        }
        s.push(newN);
    }
    //횟수가 남음
    while (k--) {
        s.pop();
    }
    //정답
    string ans = "";
    while (!s.empty()) {
        ans += to_string(s.top());
        s.pop();
    }
    for (int i = ans.size()-1; i >= 0; i--) cout << ans[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    BigNum();//큰 수
    return 0;
}
