#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,st,ed;
const int maxi = 10001;
vector<pair<int, int>> graph[maxi];//그래프
vector<pair<int, int>> backGraph[maxi];//역 추적용 그래프
int getNode[maxi] = { 0, };//진입 노드
int arrive[maxi] = { 0, };//각 노드까지 도착시각
bool visit[maxi] = { false, };//각 노드를 방문했는가?

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({ b,d });//정점, 시간
        backGraph[b].push_back({ a,d });//정점, 시간
        getNode[b]++;
    }
    cin >> st >> ed;
}
//최장거리
void LongestDist() {
    queue<pair<int, int>> q;//정점, 시간
    q.push({ st,0 });
    arrive[st] = 0;

    //탐색
    while (!q.empty()) {
        int node = q.front().first;
        int times = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextTimes = graph[node][i].second;
            getNode[nextNode]--;//간선 제거

            if (arrive[nextNode] < times + nextTimes) arrive[nextNode] = times + nextTimes;//더 긴 시간
            if (getNode[nextNode] == 0) q.push({ nextNode,arrive[nextNode] });//진입노드 0
        }
    }
    cout<< arrive[ed]<<"\n";
}
//도로 개수
void Road() {
    queue<int> q;//노드
    q.push(ed);
    visit[ed] = 0;
    int roadCnt = 0;//도로 개수

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        //다음 지점
        for (int i = 0; i < backGraph[node].size(); i++) {
            int nextNode = backGraph[node][i].first;
            int nextTimes = backGraph[node][i].second;

            //최장거리끼리
            if (arrive[node] - arrive[nextNode] == nextTimes) {
                roadCnt++;//도로 개수 증가
                if (visit[nextNode]) continue;//방문 체크
                visit[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    cout << roadCnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LongestDist();//최장거리
    Road();//도로 개수
    return 0;
}
