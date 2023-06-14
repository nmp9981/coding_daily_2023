#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int upTotal = 0; int downTotal = 0;
const int maxi = 1001;
vector < pair<int, pair<int, int>>> up;//오르막 위주
vector < pair<int, pair<int, int>>> down;//내리막 위주
int root[maxi];//각 노드의 루트노드

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m+1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        up.push_back({ d-1,{a,b} });
        down.push_back({ 1 - d,{a,b} });
    }
    //정렬
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
}
//초기화
void init() {
    for (int i = 0; i <= n; i++) root[i] = i;
}
//루트 노드
int Find(int a) {
    if (root[a] == a) return a;
    return root[a] = Find(root[a]);
}
//합치기
void Merge(int a, int b) {
    if (a > b) root[b] = a;
    else root[a] = b;
}

//오르막길
void UpStair() {
    int node = 0;
    for (int i = 0; i < up.size(); i++) {
        int dist = up[i].first;
        int x = up[i].second.first;
        int y = up[i].second.second;

        //루트노드끼리 연결
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            Merge(rootX, rootY);
            node++;
            upTotal+=dist;
        }
        if (node == n) break;//모두 연결
    }
}
//내리막길
void DownStair() {
    int node = 0;
    for (int i = 0; i < down.size(); i++) {
        int dist = down[i].first;
        int x = down[i].second.first;
        int y = down[i].second.second;

        //루트노드끼리 연결
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            Merge(rootX, rootY);
            node++;
            downTotal += dist;
        }
        if (node == n) break;//모두 연결
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    init();//초기화
    UpStair();//오르막길
    init();//초기화
    DownStair();//내리막길
    cout << abs(downTotal * downTotal - upTotal * upTotal);
    return 0;
}
