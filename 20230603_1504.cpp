#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, e,v1,v2;
const int maxi = 801;
const int inf = 100000001;
vector<pair<int, int>> graph[maxi];//그래프
int dist[maxi];//i번까지의 거리

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });//정점, 거리
        graph[b].push_back({ a,c });
    }
    cin >> v1 >> v2;
}
//다익스트라
int Dijk(int start, int end) {
    for (int i = 1; i <= n; i++) dist[i] = inf;//초기화

    priority_queue<pair<int, int>> pq;//우선순위 큐
    pq.push({ 0,start });//거리, 정점
    dist[start] = 0;

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist) continue;//더 큰 거리

        //다음 지점
        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i].first;
            int nextDist = graph[curNode][i].second;

            //더 작은거리
            if (dist[nextNode] > curDist + nextDist) {
                dist[nextNode] = curDist + nextDist;
                pq.push({ -dist[nextNode],nextNode });
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
    int res1 = Dijk(1, v1) + Dijk(v1, v2) + Dijk(v2, n);
    int res2 = Dijk(1, v2) + Dijk(v2, v1) + Dijk(v1, n);
    int res = min(res1, res2);
    if (res >= inf) cout << -1;
    else cout << res;
    return 0;
}
