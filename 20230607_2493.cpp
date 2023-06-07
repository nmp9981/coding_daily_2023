#include <iostream>
#include <stack>
using namespace std;

int n;
const int maxi = 500001;
int height[maxi];//높이
stack<pair<int,int>> s;//스택(인덱스, 높이)

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];
}
//레이저
void Layzer() {
    int towerIdx = 0;
    
    for (int i = 1; i <= n; i++) {
        //수신탑 나올때까지 
        while (!s.empty()) {
            if (s.top().second > height[i]) {//수신탑 발견
                cout << s.top().first<<" ";
                break;
            }
            s.pop();
        }
        if (s.empty()) cout << 0 << " ";//수신 불가
        s.push({ i,height[i] });
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Layzer();//레이저
    return 0;
}
