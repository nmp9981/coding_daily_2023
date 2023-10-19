#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
int root[maxi];
vector < pair<int, pair<int, int>>> com;

//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        com.push_back({ c,{a,b} });
    }
    sort(com.begin(), com.end());//비용 기준 정렬
    //초기화
    for (int i = 1; i <= n; i++) root[i] = i;
}
//각 노드의 부모노드
int Find(int r) {
    if (r == root[r]) return r;
    return root[r] = Find(root[r]);
}
//병합
void Merge(int a, int b) {
    if (b > a) root[b] = a;
    else root[a] = b;
}
//연결
void Connect() {
    int node = 0;
    int total = 0;
    int comSize = com.size();
    for (int i = 0; i < comSize; i++) {
        int cost = com[i].first;
        int x = com[i].second.first;
        int y = com[i].second.second;

        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry) {
            Merge(rx, ry);//병합
            node++;
            total += cost;
        }
        if (node == n - 1) break;//모두 연결
    }
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Connect();//연결
    return 0;
}
