#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k,w;
const int maxi = 1001;
vector<int> graph[maxi];//그래프
int times[maxi] = { 0, };//각 건물 짓는 시간
int minTimes[maxi] = { 0, };//최소 시간
int getNode[maxi] = { 0, };//진입 노드

//초기화
void init() {
    for (int i = 1; i < maxi; i++) {
        times[i] = 0;
        minTimes[i] = 0;
        getNode[i] = 0;
        graph[i].clear();
    }
}
//입력
void input() {
    cin >> n>>k;
    for (int i = 1; i <= n; i++) cin>>times[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);//a->b
        getNode[b]+=1;
    }
    cin >> w;
}
//위상정렬
void ACM() {
    queue<int> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) {
            q.push(i);
            minTimes[i] = times[i];
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            getNode[nextNode]--;

            if (getNode[nextNode] == 0) q.push(nextNode);//진입 노드 0
        
            if (minTimes[nextNode] < minTimes[node] + times[nextNode]) {
                minTimes[nextNode] = minTimes[node] + times[nextNode];
            }
        }
    }
    cout << minTimes[w] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        init();//초기화
        input();//입력
        ACM();//위상정렬
    }
    return 0;
}
