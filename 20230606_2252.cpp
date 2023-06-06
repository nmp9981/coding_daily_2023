#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
const int maxi = 32001;
vector<int> graph[maxi];
int getNode[maxi] = { 0, };//진입 차수

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        getNode[b]+=1;
    }
}
//줄 세우기
void Line() {
    queue<int> q;
    //진입 차수 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            getNode[next]--;

            if (getNode[next] == 0) q.push(next);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Line();//줄 세우기
    return 0;
}
