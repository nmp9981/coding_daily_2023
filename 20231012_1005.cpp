#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k,w;
const int maxi = 1001;
vector<int> graph[maxi];//그래프
int times[maxi] = { 0, };//각 건물을 짓는 시간
int minTimes[maxi] = { 0, };//최소 시간
int getNodes[maxi] = { 0, };//진입노드

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void Init() {
    for (int i = 0; i < maxi; i++) {
        graph[i].clear();
        times[i] = 0;
        minTimes[i] = 0;
        getNodes[i] = 0;
    }
}
//입력
void input() {
    cin >>n>>k;
    for (int i = 1; i <= n; i++) cin >> times[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);//a->b
        getNodes[b]+=1;
    }
    cin >> w;
}
//위상정렬
void ACM() {
    queue<int> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNodes[i] == 0) {
            q.push(i);
            minTimes[i] = times[i];
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            getNodes[next]-=1;

            if (getNodes[next] == 0) q.push(next);//새로운 지점

            if (minTimes[next] < minTimes[node] + times[next]) {
                minTimes[next] = minTimes[node] + times[next];
            }
        }
    }
    cout << minTimes[w]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        Init();//초기화
        input();//입력
        ACM();//위상정렬
    }
    return 0;
}
