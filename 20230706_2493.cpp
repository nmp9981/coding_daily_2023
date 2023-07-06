#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
const int maxi = 500001;
int height[maxi];//높이

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];
}
//타워 
void Tower() {
    stack<pair<int,int>> s;
    for (int i = 1; i <= n; i++) {
        //더 높은게 나올때까지 빼기
        while (!s.empty()) {
            if (s.top().first > height[i]) break;
            s.pop();
        }
        if (s.empty()) cout << 0 << " ";
        else cout << s.top().second << " ";
        s.push({ height[i],i });
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Tower();//타워
    return 0;
}
