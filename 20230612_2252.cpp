#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
const int maxi = 32001;
vector<int> graph[maxi];//그래프
int getNode[maxi] = { 0, };//진입노드 개수

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int s,t;
        cin >> s >> t;
        graph[s].push_back(t);
        getNode[t] += 1;//진입노드 증가
    }
}
//줄세우기
void Line() {
    priority_queue<int,vector<int>,greater<int>> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.top();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {//다음 지점
            int nextNode = graph[node][i];
            getNode[nextNode]--;

            if (getNode[nextNode] == 0) q.push(nextNode);//진입노드 0인것만
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Line();//줄세우기
    return 0;
}
