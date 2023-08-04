#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,s,e;
const int maxi = 1001;
const int inf = 100000000;
vector<pair<int,int>> graph[maxi];
int dist[maxi];//출발지점에서 거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b,c;
        cin >> a >> b>>c;
        graph[a].push_back({ b,c });
    }
    cin >> s >> e;
}
//다익스트라
int Dijk(int start) {
    //거리 초기화
    for (int i = 1; i <= n; i++) dist[i] = inf;

    //초기값
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });//비용, 정점

    while (!pq.empty()) {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > dist[curNode]) continue;

        //다음 지점
        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextCost = graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;

            if (dist[nextNode] > curCost + nextCost) {
                dist[nextNode] = curCost + nextCost;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
    return dist[e];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Dijk(s);//다익스트라
    return 0;
}
