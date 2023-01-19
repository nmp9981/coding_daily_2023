#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
const int maxi = 1001;
double ufo[maxi][2];//ufo좌표
double dist[maxi][maxi];//i,j번 ufo간 거리
vector<pair<double, pair<int, int>>> road;
int parent[maxi];//각 노드의 루트노드

//루트 노드 찾기
int find(int p) {
    if (parent[p] == p) return p;
    return parent[p] = find(parent[p]);
}
//입력
void input() {
    cin >>n>>m;
    for (int i = 1; i <= n; i++) cin >> ufo[i][0] >> ufo[i][1];//좌표
    //초기화
    for (int i = 1; i <= n; i++) parent[i] = i;
    //이미 있는 통로
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        road.push_back({ 0,{a,b} });
    }
}
//ufo간 거리
void DistUFO() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                double dist2 = pow(ufo[i][0] - ufo[j][0], 2) + pow(ufo[i][1] - ufo[j][1], 2);
                double dis = sqrt((double)dist2);
                road.push_back({ dis,{i,j} });
            }
        }
    }
    sort(road.begin(), road.end());//거리순 정렬
}
//크루스칼
void kruskal() {
    int node = 0; double total = 0;//연결 노드 개수, 거리
    for (int i = 0; i < road.size(); i++) {
        int x = road[i].second.first;
        int y = road[i].second.second;
        double cost = road[i].first;

        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[py] = px;
            total += cost;
            node++;
        }
        //모두 연결
        if (node == n - 1) {
            printf("%.2f", total);
            break;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    DistUFO();//ufo간 거리
    kruskal();//크루스칼
    return 0;
}
