#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, e,k;
const int maxi = 20001;
const int inf = 500000001;
int dist[maxi];//거리
vector<pair<int, int>> graph[maxi];//그래프

//입력
void input() {
    cin >> v >> e>>k;
    for (int i = 0; i < e; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점, 거리
    }
}
//다익스트라
void dijk(int start) {
    //거리 초기화
    for (int i = 1; i <= v; i++) dist[i] = inf;

    //초기값
    dist[start] = 0;
    priority_queue<pair<int, int>>pq;
    pq.push({ 0,start });//거리, 정점

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        //더 큰게 오면
        if (cur_dist > dist[cur_node]) continue;

        //다음 지점
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second;

            //더 작은 거리
            if (dist[next_node] > cur_dist + next_dist) {
                dist[next_node] = cur_dist + next_dist;
                pq.push({ -dist[next_node],next_node });
            }
        }
    }
}
//출력
void output() {
    for (int i = 1; i <= v; i++) {
        if (dist[i] >= inf) cout << "INF\n";
        else cout << dist[i]<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    dijk(k);//다익스트라
    output();//출력
    return 0;
}
