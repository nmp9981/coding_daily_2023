#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,s,e;
const int maxi = 1001;
const int inf = 500000001;
int cost[maxi];//비용
vector<pair<int, int>> graph[maxi];//그래프

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
    }
    cin >> s >> e;
}
//다익스트라
int Dijk(int start) {
    //거리 초기화
    for (int i = 1; i <= n; i++) cost[i] = inf;

    //초기값
    cost[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });//비용, 정점

    while (!pq.empty()) {
        int fee = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        //더 큰 비용이 오면 스킵
        if (fee > cost[node]) continue;

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i].first;//다음 정점
            int addFee = graph[node][i].second;//추가 요금

            //더 적은 비용
            if (cost[next] > fee + addFee) {
                cost[next] = fee + addFee;
                pq.push({ -cost[next],next });
            }
        }
    }
    return cost[e];//최소 비용
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Dijk(s);//구매
    return 0;
}
