#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int maxi = 51;
const int inf = 99999999;
int world[maxi][maxi];//맵
vector<pair<int, int>> chicken;//치킨집
vector<pair<int, int>> selectChicken;//선택한 치킨집
vector<pair<int, int>> house;//집
int chickenSize;//치킨집 총 개수
int minDist = inf;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//맨해튼 거리
int Mahatten(int x0, int x1, int y0, int y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) house.push_back({ i,j });
            else if (world[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    chickenSize = chicken.size();
}
//치킨 거리
int ChickenDist() {
    int total = 0;
    //각 집별로
    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        int dist = inf;
        //가장 가까운 치킨집
        for (int j = 0; j < selectChicken.size(); j++) {
            int cx = selectChicken[j].first;
            int cy = selectChicken[j].second;
            dist = min(dist, Mahatten(hx, cx, hy, cy));
        }
        total += dist;
    }
    return total;
}
//치킨집 선택
void Select(int idx,int cnt) {
    //모두 선택
    if (cnt == m) {
        minDist = min(minDist, ChickenDist());
        return;
    }
    //다음 지점
    for (int k = idx; k < chickenSize; k++) {
        int x = chicken[k].first;
        int y = chicken[k].second;
        selectChicken.push_back({ x,y });
        Select(k + 1, cnt + 1);
        selectChicken.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Select(0,0);//치킨집 선택
    cout << minDist;//출력
    return 0;
}
