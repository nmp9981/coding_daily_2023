#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
vector<pair<int,pair<int, int>>> graph;//그래프
int root[maxi];//각 노드의 루트 노드

//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({ c,{a,b} });
    }
    sort(graph.begin(), graph.end());//거리순 정렬
}
//초기화
void init() {
    for (int i = 1; i <= n; i++) root[i] = i;
}
//루트노드
int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}
//병합
void Merge(int a, int b) {
    if (a > b) root[a] = b;
    else root[b] = a;
}
//연결
void Connect() {
    int total = 0;
    int node = 0;
    for (int i = 0; i < graph.size(); i++) {
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int cost = graph[i].first;

        //각 노드의 루트 노드
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry) {
            Merge(rx, ry);
            total += cost;
            node++;
        }
        //모두 연결
        if (node == n - 1) {
            cout << total;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    init();//초기화
    Connect();//연결
    return 0;
}
