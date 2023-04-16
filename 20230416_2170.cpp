#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> Lines;//선

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Lines.push_back({ a,b });
    }
    sort(Lines.begin(), Lines.end());//시작점 순으로 정렬
}
//선 그리기
int Draw() {
    int st = Lines[0].first;
    int end = Lines[0].second;
    int total = 0;//총 길이

    for (int i = 1; i < n; i++) {
        int left = Lines[i].first;
        int right = Lines[i].second;

        if (end < left) {//끊어짐
            total += (end - st);
            st = left;
            end = right;
        }
        else if (left <= end && end < right) end = right;
    }
    total += (end - st);//마지막 막대
    return total;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Draw();//그리기
    return 0;
}
