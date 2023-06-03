#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, e,v1,v2;
const int maxi = 11;
const int inf = 10001;
vector<int> graph[maxi];//그래프
int people[maxi];//인구
bool isSelect[maxi];//선택 여부
bool visit[maxi];//방문 여부
int minDiff = inf;//최소 차이

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> people[i];
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            graph[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) isSelect[i] = false;//초기화
}
//연결 여부
bool isConnected(vector<int> team) {
    for (int i = 1; i <= n; i++) visit[i] = false;
    queue<int> q;
    q.push(team[0]);
    visit[team[0]] = true;
   
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        //다음 지점
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (visit[next]) continue;//이미 방문
            //해당 팀에 있는가?
            for (int j = 0; j < team.size(); j++) {
                if (next == team[j]) {
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    for (int i = 0; i < team.size(); i++) {
        if (!visit[team[i]]) return false;//연결 실패
    }
    return true;
}
//인구차
int DiffPeople() {
    vector<int> redTeam;
    vector<int> blueTeam;

    //팀 배정
    for (int i = 1; i <= n; i++) {
        if (isSelect[i]) redTeam.push_back(i);
        else blueTeam.push_back(i);
    }
    
    //둘다 연결
    if (isConnected(redTeam) && isConnected(blueTeam)) {
        int redSum = 0;
        int blueSum = 0;
        for (int i = 0; i < redTeam.size(); i++) redSum += people[redTeam[i]];//레드팀
        for (int i = 0; i < blueTeam.size(); i++) blueSum += people[blueTeam[i]];//블루팀
        return abs(redSum - blueSum);
    }
    return inf;
}
//팀 선정
void Team(int idx,int cnt) {
    if (cnt > (n/2)) return;//인원 초과
    //팀 선정
    if (cnt>=1 && cnt<=(n/2)) minDiff = min(minDiff, DiffPeople());//연결 여부
    
    //다음 팀원
    for (int i = idx; i <= n; i++) {
        if (isSelect[i]) continue;//이미 선택
        isSelect[i] = true;
        Team(i + 1, cnt + 1);
        isSelect[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Team(1,0);//팀 선정
    //결과
    if (minDiff >= inf) cout << -1;
    else cout << minDiff;
    return 0;
}
