#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 50001;
const int inf = 300000000;
vector<pair<int, int>> graph[maxi];//그래프
int dist[maxi];//거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//초기화
void init() {
    for (int i = 0; i < maxi; i++) dist[i] = inf;
}
//입력
void input() {
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });//노드, 비용
        graph[b].push_back({ a,c });
    }
}
//다익스트라
void Dijk() {
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,1 });//비용, 노드

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) continue;//더 많은 비용

        //다음 노드
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextCost = graph[node][i].second;

            //더 작은 거리
            if (cost + nextCost < dist[nextNode]) {
                dist[nextNode] = cost + nextCost;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
    cout << dist[n];//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Dijk();//다익스트라
    return 0;
}
