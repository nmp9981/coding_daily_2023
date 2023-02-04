#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 501;
vector<pair<int, int>> elect;//전깃줄

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        elect.push_back({ start,end });
    }
    sort(elect.begin(), elect.end());//정렬
}
//전깃줄 제거
int removeLine() {
    vector<int> LIS;//남기는 전깃줄
    for (int i = 0; i < n; i++) {
        int x = elect[i].second;
        //비거나 끝보다 더 크면
        if (LIS.size() == 0 || LIS[LIS.size()-1] < x) LIS.push_back(x);
        else {
            int idx = lower_bound(LIS.begin(), LIS.end(), x)-LIS.begin();//위치
            LIS[idx] = x;
        }
    }
    return LIS.size();
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    cout<<n-removeLine();//전깃줄 제거
    return 0;
}
