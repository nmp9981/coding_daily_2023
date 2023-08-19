#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
const int maxi = 50001;
const int inf = 500000000;
vector<pair<int,int>> graph[maxi];//그래프
int dist[maxi];//각 지점까지의 최단거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });//정점, 비용
        graph[b].push_back({ a,c });
    }
    for (int i = 0; i < maxi; i++) dist[i] = inf;
}
//다익스트라
void Dijk() {
    priority_queue<pair<int, int>> pq;
    dist[1] = 0;
    pq.push({ 0,1 });//비용, 노드
    
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost) continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int nextCost = graph[node][i].second;
            int nextNode = graph[node][i].first;

            if (dist[nextNode] > cost + nextCost) {
                dist[nextNode] = cost + nextCost;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
    cout << dist[n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Dijk();//다익스트라
    return 0;
}
