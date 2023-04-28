#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,d,c;
const int maxi = 10001;
const int inf = 555555555;
vector<pair<int, int>> graph[maxi];//그래프
int dist[maxi];//출발 지점으로부터의 거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    cin >> n >> d >> c;
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        graph[i].clear();
    }
}
//입력
void input() {
    for (int i = 0; i < d; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        graph[b].push_back({ a,s });
    }
}
//다익스트라
void Dijk(int start) {
    dist[start] = 0;
    priority_queue<pair<int,int>> q;//거리, 노드
    q.push({ 0,start });

    while (!q.empty()) {
        int node = q.top().second;//정점
        int curDist = -q.top().first;//거리
        q.pop();

        //더 먼 거리
        if (curDist > dist[node]) continue;

        //더 작은거리
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextDist = graph[node][i].second;

            if (dist[nextNode] > curDist + nextDist) {
                dist[nextNode] = curDist + nextDist;
                q.push({ -dist[nextNode],nextNode });
            }
        }
    }
}
//바이러스 검사
void Virus() {
    int total = 0;
    int times = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] < inf) {
            total++;
            times = max(times, dist[i]);
        }
    }
    cout << total << " " << times << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        init();//초기화
        input();//입력
        Dijk(c);//다익스트라
        Virus();//바이러스 검사
    }
    return 0;
}
