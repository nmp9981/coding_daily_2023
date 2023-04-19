#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v,e,start;
const int maxi = 20001;
const int inf = 500000001;
vector<pair<int, int>> graph[maxi];
int dist[maxi];//start부터에서의 거리

//입력
void input() {
    cin >> v>>e>>start;
    for (int i = 0; i < e; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점 , 거리
    }
}
//다익스트라
void Dijk(int start) {
    for (int i = 1; i <= v; i++) dist[i] = inf;//초기화
    
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });//거리, 정점

    while (!pq.empty()) {
        int node = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        //더 큰 거리가 오면
        if (dist[node] < curDist) continue;

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextDist = graph[node][i].second;

            //더 작은 거리가 오면
            if (dist[nextNode] > nextDist + curDist) {
                dist[nextNode] = nextDist + curDist;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
}
//출력
void output() {
    for (int i = 1; i <= v; i++) {
        if (dist[i] >= inf) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Dijk(start);//다익스트라
    output();//출력
    return 0;
}
