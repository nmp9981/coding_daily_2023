#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v,e,k;
const int maxi = 20001;
const int inf = 555555555;
vector<pair<int, int>> graph[maxi];
int dist[maxi];//거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> v>>e>>k;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({ b,w });//노드, 거리
    }
}
//다익스트라
void Dijk() {
    //거리 초기화
    for (int i = 1; i <= v; i++) dist[i] = inf;

    //시작 지점
    dist[k] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,k });//거리 , 노드

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > dist[curNode]) continue;//더 먼 거리

        //다음 지점
        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextDist = graph[curNode][i].second;
            int nextNode = graph[curNode][i].first;

            //더 가까운 거리
            if (dist[nextNode] > curDist + nextDist) {
                dist[nextNode] = curDist + nextDist;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
    //출력
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
    Dijk();//다익스트라
    return 0;
}
