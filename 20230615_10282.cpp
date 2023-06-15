#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,d,c;
const int maxi = 10001;
const int inf = 543212345;
vector<pair<int, int>> graph[maxi];//그래프
int dist[maxi];//i로부터의 거리

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    for (int i = 0; i < maxi; i++) {
        dist[i] = inf;
        graph[i].clear();
    }
}
//입력
void input() {
    cin >> n>>d>>c;
    for (int i = 0; i < d; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        graph[b].push_back({ a,s });//정점 ,거리
    }
}
//감염
void Inspection() {
    priority_queue<pair<int, int>>pq;
    pq.push({ 0,c });//거리, 정점
    dist[c] = 0;

    while (!pq.empty()) {
        int weight = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < weight) continue;//더 큰 거리

        for (int i = 0; i < graph[node].size(); i++) {
            int nextWeight = graph[node][i].second;
            int nextNode = graph[node][i].first;

            if (dist[nextNode] > weight + nextWeight) {//더 작은 거리
                dist[nextNode] = weight + nextWeight;
                pq.push({ -dist[nextNode],nextNode });
            }
        }
    }
}
//정산
void Account() {
    int cnt = 0; int times = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] < inf) {
            cnt++;
            times = max(times, dist[i]);
        }
    }
    cout << cnt << " " << times << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        init();//초기화
        input();//입력
        Inspection();//감염
        Account();//정산
    }
    return 0;
}
