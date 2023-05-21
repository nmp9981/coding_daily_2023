#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, e,v1,v2,res;
const int maxi = 801;
const int inf = 100000000;
vector<pair<int,int>> graph[maxi];//그래프(정점, 거리)
int dist[maxi];//start에서 부터의 거리

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    cin >> v1>>v2;
}
//다익스트라
int Dijk(int start,int end) {
    //거리 초기화
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });//거리, 정점

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curDist > dist[node]) continue;//더 큰 거리

        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextDist = graph[node][i].second;

            if (curDist + nextDist < dist[nextNode]) {//거리합이 더 작으면
                dist[nextNode] = curDist + nextDist;
                pq.push({-dist[nextNode],nextNode});
            }
        }
    }
    return dist[end];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    //다익스트라
    int result1 = 0; int result2 = 0;
    result1 += Dijk(1,v1);
    result1 += Dijk(v1, v2);
    result1 += Dijk(v2, n);

    result2 += Dijk(1, v2);
    result2 += Dijk(v2, v1);
    result2 += Dijk(v1, n);
    res = min(result1, result2);
    if (res >= inf) cout << -1;
    else cout << res;
    return 0;
}
