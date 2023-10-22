#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int maxi = 10011;
int depth[maxi];//꼭지점에서의 거리
vector<pair<int, int>> graph[maxi];//그래프
int resultNode[2] = { 0,0 };
int resultDist[2] = { 0,0 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void Init() {
    for (int i = 1; i <= n; i++) depth[i] = -1;
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
}
//bfs
void BFS(int start,int idx) {
    depth[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i].first;
            int dist = graph[x][i].second;

            if (depth[nx] == -1) {
                depth[nx] = depth[x] + dist;
                q.push(nx);
            }
        }
    }
    //가장 먼 노드
    for (int i = 1; i <= n; i++) {
        if (resultDist[idx] < depth[i]) {
            resultNode[idx] = i;
            resultDist[idx] = depth[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Init();//초기화
    BFS(1,0);
    Init();//초기화
    BFS(resultNode[0],1);
    cout << resultDist[1];
    return 0;
}
