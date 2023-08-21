#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
const int maxi = 2001;
vector<int> graph[maxi];//그래프
bool visit[maxi];//방문 여부
bool isFriends;//친구가 존재하는가?

//입력
void input() {
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);//양방향
        graph[b].push_back(a);
    }
    isFriends = false;
}
//깊이 우선 탐색
void dfs(int idx, int depth) {
    //깊이 4인것이 존재?
    if (depth == 4) {
        isFriends = true;
        return;
    }
    //다음 친구
    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];
        if (visit[next]) continue;
        visit[next] = true;
        dfs(next, depth + 1);
        visit[next] = false;
    }
}
//친구관계
void Friends() {
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {//미방문 지역만
            visit[i] = true;
            dfs(i, 0);
            if (isFriends) break;//친구관계 존재
            visit[i] = false;
        }
    }
}
//출력
void output() {
    if (isFriends) cout << 1;
    else cout << 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Friends();//친구관계
    output();//출력
    return 0;
}
