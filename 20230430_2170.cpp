#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,l,r;
vector<pair<int,int>> line;//선

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l>>r;
        line.push_back({ l,r });
    }
    sort(line.begin(), line.end());//시작 지점 기준으로 정렬
}
//그리기
void Draw() {
    int left = line[0].first;
    int right = line[0].second;
    int total = 0;//총 길이
    for (int i = 1; i < line.size(); i++) {//각 버스에 대해
        if (right < line[i].first) {//새로운 선
            total += (right - left);//누적 길이
            left = line[i].first;
            right = line[i].second;
        }
        else if (left < line[i].first && line[i].first <= right) {//겹치는 선
            if (right < line[i].second) right = line[i].second;
        }
    }
    cout << total + right - left;//총 길이 출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Draw();//버스
    return 0;
}
