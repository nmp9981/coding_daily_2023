#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
const int maxi = 10001;
vector<pair<int,pair<int,int>>> graph;//그래프
int root[maxi];//각 노드의 루트노드

//초기화
void init() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) root[i] = i;
}
//입력
void input() {
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({ c,{a,b} });//비용, 간선
    }
    sort(graph.begin(), graph.end());//비용 기준으로 정렬
}
//루트노드 찾기
int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}
//병합
void Merge(int a, int b) {
    if (b > a) root[b] = a;
    else root[a] = b;
}
//크루스칼
void Kruskal() {
    int node = 0;
    int result = 0;
    for (int i = 0; i < m; i++) {
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int cost = graph[i].first;

        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            Merge(rootX, rootY);
            node++;
            result += cost;
        }

        //완료
        if (node == n - 1) {
            int add = node * (node - 1) * t / 2;//추가량
            cout << result + add;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Kruskal();//크루스칼
    return 0;
}
