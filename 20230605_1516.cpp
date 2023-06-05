#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 501;
vector<int> graph[maxi];
int getNode[maxi];//진입 노드 개수
int buildTime[maxi];//각 건물을 짓기 소요시간
int buildComplete[maxi];//완공 시간

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> buildTime[i];
        while (true) {
            int m;cin >> m;
            if (m == -1) break;
            else {
                graph[m].push_back(i);
                getNode[i]++;
            }
        }
    }
}
//건축
void Build() {
    queue<int> q;
    //진입노드가 0인것을 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) {
            q.push(i);
            buildComplete[i] = buildTime[i];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int next = graph[x][i];
            getNode[next]--;
            buildComplete[next] = max(buildComplete[next], buildComplete[x] + buildTime[next]);

            if (getNode[next] == 0) q.push(next);//사전 작업 완료
        }
    }
}
//출력
void output() {
    for (int i = 1; i <= n; i++) cout << buildComplete[i]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Build();//건축
    output();//출력
    return 0;
}
