#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int maxi = 10001;
vector<int> graph[maxi];
int getNode[maxi];//진입 노드
int times[maxi];//각 노드 소요시간
int minTimes[maxi];//각 노드별 총 시간

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> times[i];
        int k;cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            graph[x].push_back(i);
            getNode[i]++;
        }
    }
}
//작업
void Work() {
    //진입노드 0
    queue<int> q;
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

            minTimes[nextNode] = max(minTimes[nextNode], minTimes[node] + times[nextNode]);
            if (getNode[nextNode] == 0) q.push(nextNode);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, minTimes[i]);
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Work();//작업
    return 0;
}
