#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 51;
const int inf = 100000000;
int chickenDist = inf;
int city[maxi][maxi];//도시
vector<pair<int, int>> house;//집
vector<pair<int, int>> chicken;//치킨
vector<pair<int, int>> selectChicken;//선택한 치킨

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) house.push_back({ i,j });
            else if (city[i][j] == 2) chicken.push_back({ i,j });
        }
    }
}
//치킨 거리
int ChickenDist() {
    int dist = 0;
    for (int i = 0; i < house.size(); i++) {//각 집에대해
        int minDist = inf;
        for (int j = 0; j < selectChicken.size(); j++) {//가장 가까운 치킨집
            int dx = abs(house[i].first - selectChicken[j].first);
            int dy = abs(house[i].second - selectChicken[j].second);
            minDist = min(minDist, dx + dy);//치킨 거리
        }
        dist += minDist;
    }
    return dist;
}
//선택하기
void Select(int idx,int cnt) {
    //m개를 고름
    if (cnt == m) {
        chickenDist = min(chickenDist,ChickenDist());//치킨 거리
        return;
    }
    //다음 지점
    for (int i = idx; i < chicken.size(); i++) {
        selectChicken.push_back(chicken[i]);
        Select(i + 1,cnt+1);
        selectChicken.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Select(0,0);//치킨집 선택
    cout << chickenDist;//출력
    return 0;
}
