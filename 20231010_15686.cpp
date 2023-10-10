#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 51;
int ans = maxi * maxi * maxi;
int chickenSize,houseSize;
int world[maxi][maxi];//지도
vector<pair<int, int>> house;//집
vector<pair<int, int>> chicken;//치킨
vector<pair<int, int>> selectedChicken;//선택한 치킨집
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) house.push_back({ i,j });
            else if (world[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    houseSize = house.size();
    chickenSize = chicken.size();
}
//치킨거리
int DistChicken() {
    int total = 0;
    for (int i = 0; i < houseSize; i++) {//각 집을 기준
        int minDist = 2501;
        for (int j = 0; j < m; j++) {
            int distX = abs(house[i].first - selectedChicken[j].first);
            int distY = abs(house[i].second - selectedChicken[j].second);
            minDist = min(minDist, distX + distY);
        }
        total += minDist;
    }
    return total;
}
//M개를 고른다.
void Select(int idx,int cnt) {
    //m개를 고름
    if (cnt == m) {
        ans = min(ans,DistChicken());//치킨거리
        return;
    }
    //다음 지점
    for (int i = idx; i < chickenSize; i++) {
        selectedChicken.push_back(chicken[i]);
        Select(i + 1, cnt + 1);
        selectedChicken.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Select(0,0);//m개 고르기
    cout << ans;//정답 출력
    return 0;
}
