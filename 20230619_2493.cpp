#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
const int maxi = 500001;
int height[maxi];//높이
stack<pair<int,int>> s;//인덱스, 높이
vector<int> ans;//정답 타워

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];
}
//레이저
void Laser() {
    for (int i = 1; i <= n; i++) {
        //더 큰게 나올때까지 빼줌
        while (!s.empty()) {
            if (s.top().second < height[i]) s.pop();
            else {
                ans.push_back(s.top().first);
                break;
            }
        }
        if (s.empty()) ans.push_back(0);
        s.push({i, height[i] });
    }
}
//출력
void output() {
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Laser();//레이저
    output();//츨력
    return 0;
}
