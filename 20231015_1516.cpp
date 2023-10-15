#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int maxi = 501;
int buildTime[maxi];//빌딩 시간
int result[maxi];//결과
int getNode[maxi];//진입 노드
vector<int> graph[maxi];//그래프
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >>n;
    for (int i = 1; i <=n; i++) {
        cin>>buildTime[i];
        while (true) {
            int x; cin >> x;
            if (x == -1) break;
            getNode[i]++;
            graph[x].push_back(i);
        }
    }
}
//위상정렬
void ACM() {
    queue<int> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) {
            q.push(i);
            result[i] = buildTime[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        //다음 지점
        for (int k = 0; k < graph[cur].size(); k++) {
            int next = graph[cur][k];
            getNode[next] -= 1;
            if (getNode[next] == 0) q.push(next);//모두 완료

            result[next] = max(result[next],result[cur]+buildTime[next]);
        }
    }
    //출력
    for (int i = 1; i <= n; i++) cout << result[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ACM();//위상정렬
    return 0;
}
