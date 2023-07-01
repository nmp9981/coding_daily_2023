#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int maxi = 501;
const int inf = 100001;
vector<int> graph[maxi];//그래프
int buildTime[maxi];//완공 시간
int minTimes[maxi];//최소 완공 시간
int getNode[maxi];//진입 노드

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> buildTime[i];
        minTimes[i] = buildTime[i];
        while (true) {
            int x; cin >> x;
            if (x == -1) break;//입력 종료
            getNode[i]++;
            graph[x].push_back(i);
        }
    }
}
//건물 짓기
void Building() {
    //진입노드 0인것 모두 큐에 넣기
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) {
            q.push(i);
            minTimes[i] = buildTime[i];
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            getNode[nextNode]--;
            minTimes[nextNode] = max(minTimes[nextNode],minTimes[node] + buildTime[nextNode]);

            if (getNode[nextNode] == 0) q.push(nextNode);//진입 노드 0
        }
    }
}
//출력
void output() {
    for (int i = 1; i <= n; i++) cout << minTimes[i] << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Building();//건물 짓기
    output();//출력
    return 0;
}
