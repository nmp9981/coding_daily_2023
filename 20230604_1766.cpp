#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
const int maxi = 32001;
vector<int> tree[maxi];
int getNode[maxi];//각 노드의 진입노드 개수

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);//a->b
        getNode[b]+=1;//진입 노드 개수 증가
    }
}
//문제 풀기(위상 정렬+최소힙)
void Solve() {
    priority_queue<int, vector<int>, greater<int>> pq;//최소힙(쉬운것부터)
    //진입차수 0인것을 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) pq.push(i);//루트 노드
    }

    while (!pq.empty()) {
        int node = pq.top();//현재 노드
        pq.pop();
        cout << node << " ";//출력
        
        //다음 지점
        for (int i = 0; i < tree[node].size(); i++) {
            int next = tree[node][i];
            getNode[next] -= 1;//진입 노드개수 감소

            if (getNode[next] == 0)  pq.push(next);//모든 선행 조건 만족
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Solve();//문제 풀기
    return 0;
}
