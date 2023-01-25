#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,st,ed;
const int maxi = 1001;
const int inf = 700000001;
int dist[maxi];//i번에서의 거리
vector<pair<int, int>> graph[maxi];

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점, 거리
    }
    cin >> st >> ed;
}
//다익스트라
void Dijk() {
    //초기화
    for (int i = 0; i < maxi; i++) dist[i] = inf;
    dist[st] = 0;
    priority_queue<pair<int, int>> pq;//비용, 정점
    pq.push({ 0,st });

    while (!pq.empty()) {
        int fee = -pq.top().first;//비용
        int node = pq.top().second;//정점
        pq.pop();

        //더 적은 비용이 나올때만
        if (fee > dist[node]) continue;

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i].first;
            int addDist = graph[node][i].second;

            //비용의 합이 더 작을 경우에만 갱신
            if (addDist + fee < dist[next]) {
                dist[next] = addDist + fee;
                pq.push({ -dist[next],next });
            }
        }
    }
    cout << dist[ed];//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Dijk();//다익스트라
    return 0;
}
