#include <iostream>
#include <vector>
using namespace std;

int n;
int farNode = 0; int maxDist = 0;
const int maxi = 10001;
const int inf = -700000001;
int dist[maxi];//i번에서의 거리
vector<pair<int, int>> graph[maxi];//그래프

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    for (int i = 1; i <=n; i++) dist[i] = inf;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점, 거리
        graph[b].push_back({ a,d });//정점, 거리
    }
}
//가장 깊은노드 구하기
void DeepNode(int node) {
    //다음 노드
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].first;
        int addDist = graph[node][i].second;

        if (dist[next] == inf) {//미방문인 지점
            dist[next] = dist[node] + addDist;
            DeepNode(next);
        }
    }
}
//가장 먼 노드
void FarNode() {
    farNode = 0; maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (maxDist < dist[i]) {//더 먼 거리
            maxDist = dist[i];
            farNode = i;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    init();//초기화
    dist[1] = 0;
    DeepNode(1);//가장 깊은 노드 구하기
    FarNode();//가장 먼 노드 구하기

    init();//초기화
    dist[farNode] = 0;
    DeepNode(farNode);//가장 깊은 노드 구하기
    FarNode();//가장 먼 노드 구하기
    cout << maxDist;//출력
    return 0;
}
