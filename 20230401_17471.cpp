#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n;
const int maxi = 11;
const int inf = 1000001;
int people[maxi];//인구 수
vector<int> graph[maxi];//그래프
bool selected[maxi];//선택한 지역
bool visit[maxi];//방문 여부
int minDiff = inf;//인구 차이

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> people[i];//인구 수
    //그래프
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int node; cin >> node;
            graph[i].push_back(node);
        }
    }
}
//팀 연결
bool isTeamConnect(vector<int> team) {
    memset(visit, false, sizeof(visit));//초기화
    queue<int> q;
    q.push(team[0]);
    visit[team[0]] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        //다음 지점
        for (int k = 0; k < graph[x].size(); k++) {
            int next = graph[x][k];
            if (visit[next]) continue;//방문 조건
            //해당 팀인가?
            for (int mem : team) {
                if (mem == next) {
                    q.push(mem);
                    visit[mem] = true;
                }
            }
        }
    }
    //검사
    for (int mem : team) {
        if (visit[mem] == false) return false;
    }
    return true;
}

//연결하기
bool isConnect() {
    //팀 나누기
    vector<int> redTeam;
    vector<int> blueTeam;
    for (int i = 1; i <= n; i++) {
        if (selected[i] == true) redTeam.push_back(i);
        else blueTeam.push_back(i);
    }
    if (redTeam.size() == 0 || blueTeam.size() == 0) return false;

    //연결
    if (!isTeamConnect(redTeam)) return false;
    if (!isTeamConnect(blueTeam)) return false;

    return true;
}
//인구 차
int DiffPeople() {
    int red = 0;int blue = 0;
    for (int i = 1; i <= n; i++) {
        if (selected[i] == true) red += people[i];
        else blue += people[i];
    }
    return abs(red - blue);
}
//구역 나누기
void Area(int idx,int cnt) {
    //인원 초과
    if (cnt > (n / 2)) return;
    //모두 나눔
    if (cnt >= 1 && cnt <= (n / 2)) {
        //연결 가능한가?
        if (isConnect()) minDiff = min(minDiff, DiffPeople());//인구 차
        
    }
    //다음 구역
    for (int i = idx; i <= n; i++) {
        if (selected[i]) continue;//이미 선택
        selected[i] = true;
        Area(i+1,cnt + 1);
        selected[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Area(1,0);//구역 나누기
    //출력
    if (minDiff == inf) cout << -1;
    else cout << minDiff;
    return 0;
}
