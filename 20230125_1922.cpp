#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
vector<pair<int, pair<int, int>>> com;//컴퓨터
int root[maxi];//각 노드의 루트노드

//부모노드 찾기
int find(int p) {
    if (root[p] == p) return p;
    return root[p] = find(root[p]);
}
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
        com.push_back({ c,{a,b} });//비용, 노드
    }
    for (int i = 1; i <= n; i++) root[i] = i;//루트노드 초기화
    sort(com.begin(), com.end());//비용 기준으로 정렬
}
//연결
void Connect() {
    int node = 0; int total = 0;//연결 노드 개수, 총 비용
    for (int i = 0; i < m; i++) {
        int x = com[i].second.first;
        int y = com[i].second.second;
        int cost = com[i].first;

        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {//루트노드가 서로 다르면 연결
            root[rootY] = rootX;//연결
            node++;
            total += cost;
        }
        //연결 완료
        if (node == n - 1){
            cout << total;
            break;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Connect();//연결
    return 0;
}
