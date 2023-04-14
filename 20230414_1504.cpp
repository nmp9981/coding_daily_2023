#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,e,v1,v2;
const int maxi = 801;
const int inf = 500000000;
vector<pair<int,int>> graph[maxi];//그래프
int dist[maxi];//기준에서 j번까지 거리

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점, 거리
        graph[b].push_back({ a,d });
    }
    cin >> v1 >> v2;
}
//다익스트라
int dijk(int start, int end) {
    //거리 초기화
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;//최대힙
    pq.push({ 0,start });//거리, 정점

    while (!pq.empty()) {
        int node = pq.top().second;//현재 노드
        int currentDist = -pq.top().first;//최솟값을 꺼내야함
        pq.pop();

        //이전 거리보다 더 큼
        if (currentDist > dist[node]) continue;

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;//정점
            int nextDist = graph[node][i].second;//거리

            //더 작은 거리가 나오면 업데이트
            if (currentDist + nextDist < dist[nextNode]) {
                dist[nextNode] = currentDist + nextDist;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
    return dist[end];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    int result1 = 0; int result2 = 0;
    //1->v1->v2->n
    result1 += dijk(1, v1);
    result1 += dijk(v1, v2);
    result1 += dijk(v2, n);
    //1->v2->v1->n
    result2 += dijk(1, v2);
    result2 += dijk(v2, v1);
    result2 += dijk(v1, n);
    
    //최단거리
    int result = min(result1, result2);
    if (result >= inf)cout << -1;
    else cout << result;
    return 0;
}
