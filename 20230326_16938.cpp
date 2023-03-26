#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,l,r,x;
const int maxi = 15;
vector<int> level;//난이도
vector<int> problem;//문제
bool isSelected[maxi];//선택했는가?
int caseNum = 0;//방법의 수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>l>>r>>x;
    for (int i = 0; i < n; i++) {
        int difficulty; cin >> difficulty;
        level.push_back(difficulty);
    }
    sort(level.begin(), level.end());//난이도 순 정렬
}
//캠프
void Camp(int cnt,int idx,int sum) {
    if (cnt >= 2) {//2문제 이상 선택
        if (sum >= l && sum <= r) {
            if (problem[cnt - 1] - problem[0] >= x) caseNum++;
        }
    }
    //다음 문제
    for (int i = idx; i < n; i++) {
        if (isSelected[i]) continue;//이미 선택함
        problem.push_back(level[i]);
        isSelected[i] = true;
        int nextSum = sum + level[i];
        Camp(cnt + 1, i + 1, nextSum);
        problem.pop_back();
        isSelected[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Camp(0,0,0);//캠프
    cout << caseNum;//출력
    return 0;
}
