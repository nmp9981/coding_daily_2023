#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,d;
int enemyCnt = 0;
const int maxi = 15;
int oriWorld[maxi][maxi];//월드(원본)
int world[maxi][maxi];//월드
vector<int> bowMan;//궁수 위치

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) world[i][j] = oriWorld[i][j];
    }
}
//입력
void input() {
    cin >> n>>m>>d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> oriWorld[i][j];
    }
}
//맵 갱신
void MapSetting() {
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < m; j++) world[i][j] = world[i-1][j];
    }
}
//거리
int Dist(int r, int c,int bowX) {
    return n - r + abs(c - bowX);
}
//공격
int Attack(int wave) {
    int kills = 0;
    vector<pair<int, int>> attackEnemy;//공격받는 적의 위치
    for (int k = 0; k < 3; k++) {//각 궁수별로
        vector<pair<int,pair<int,int>>> enemy;//적(거리, 열, 행)
        //적 정보
        for (int i = wave; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (world[i][j] == 1) {//적
                    int attackDist = Dist(i, j, bowMan[k]);//사정거리
                    if (attackDist <= d) enemy.push_back({ attackDist, {j,i } });//사정거리 내
                }
            }
        }
        
        if (enemy.size() > 0) {//적이 있을때
            sort(enemy.begin(), enemy.end());//거리, 열 순으로 정렬
            attackEnemy.push_back({ enemy[0].second.second,enemy[0].second.first });//행, 열
        }
    }

    //몹 처치
    for (int k = 0; k < attackEnemy.size(); k++) {
        int x = attackEnemy[k].first;
        int y = attackEnemy[k].second;
        if (world[x][y] == 1) {
            world[x][y] = 0;
            kills++;
        }
    }
    return kills;
}
//게임 플레이
int Play() {
    int total = 0;
    for (int wave = 0; wave < n; wave++) {
        total+=Attack(wave);//공격
        MapSetting();//맵 갱신
    }
    return total;
}
//궁수 선택
void BowManArrange(int idx,int cnt) {
    //궁수를 모두 선택
    if (cnt == 3) {
        init();//초기화
        enemyCnt = max(enemyCnt, Play());
        return;
    }
    //다음 궁수
    for (int i = idx; i < m; i++) {
        bowMan.push_back(i);
        BowManArrange(i + 1, cnt + 1);
        bowMan.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    BowManArrange(0, 0);//궁수 선택
    cout << enemyCnt;//출력
    return 0;
}
