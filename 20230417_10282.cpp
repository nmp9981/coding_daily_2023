#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,d,c;
const int maxi = 10001;
const int inf = 500000001;
int times[maxi];//감염시간
vector<pair<int, int>> graph[maxi];//그래프

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    cin >> n >> d >> c;
    for (int i = 1; i <= n; i++) {
        times[i] = inf;
        graph[i].clear();
    }
}
//입력
void input() {
    for (int i = 0; i < d; i++) {
        int a, b,s;
        cin >> a >> b>>s;
        graph[b].push_back({ a,s });//노드, 시간
    }
}
//감염
void Infection() {
    //초기값
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,c });//시간, 정점
    times[c] = 0;

    while (!pq.empty()) {
        int curTime = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curTime > times[node]) continue;//더 큰 값이 오면

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextTime = graph[node][i].second;
            
            //더 적은 시간
            if (times[nextNode] > curTime + nextTime) {
                times[nextNode] = curTime + nextTime;
                pq.push({-times[nextNode],nextNode});
            }
        }
    }
    //결과
    int cnt = 0; int infecTime = 0;
    for (int i = 1; i <= n; i++) {
        if (times[i] >= inf) continue;
        cnt++;
        infecTime = max(infecTime, times[i]);
    }
    cout << cnt << " " << infecTime << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while (t--) {
        init();//초기화
        input();//입력
        Infection();//감염
    }
    return 0;
}
