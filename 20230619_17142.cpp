#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 51;
int minTime;//최소 시간
int inf = 51*51*51;
int virusSize;//바이러스 총 개수
int worldOri[maxi][maxi];//지도 원본
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 여부
int blankCnt=0;//빈칸 개수
vector<pair<int, int>> virus;//바이러스 위치
vector<pair<int, int>> activeVirus;//활성화 바이러스
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> worldOri[i][j];
            if (worldOri[i][j] == 2) virus.push_back({ i,j});//바이러스
            if (worldOri[i][j] == 0) blankCnt++;//빈칸 개수
        }
    }
    virusSize = virus.size();
    minTime = inf;
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            world[i][j] = worldOri[i][j];
            visit[i][j] = -1;
        }
    }
}
//바이러스 확산
int Spread() {   
    int restBlank = blankCnt;//남은 빈칸 개수
    int times = 0;
    queue<pair<int, int>> q;
    //초기 지점
    for (int k = 0; k < m; k++) {
        int stX = activeVirus[k].first;
        int stY = activeVirus[k].second;
        q.push({ stX,stY });
        visit[stX][stY] = 0;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 초과
            if (visit[nx][ny] != -1) continue;//이미 방문
            if (world[nx][ny] == 1) continue;//벽

            if (world[nx][ny] == 0) restBlank--;//빈칸 제거
            visit[nx][ny] = visit[x][y] + 1;
            times = max(visit[nx][ny], times);
            q.push({ nx,ny });
            world[nx][ny] = 2;

            if (restBlank == 0) return times;//빈칸 모두 탐색
        }
    }
    if (restBlank > 0) return inf;//빈칸 검사
    return times;
}
//바이러스 선택
void SelectedVirus(int idx, int cnt) {
    //모두 선택
    if (cnt == m) {
        init();//초기화
        minTime = min(minTime,Spread());//확산
        return;
    }
    //활성화 바이러스 선택
    for (int i = idx; i < virusSize; i++) {
        int nx = virus[i].first;
        int ny = virus[i].second;
        activeVirus.push_back({ nx,ny });
        SelectedVirus(i + 1, cnt + 1);//다음 바이러스
        activeVirus.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (blankCnt == 0) minTime = 0;//처음부터 다 참
    else SelectedVirus(0,0);//활성화 바이러스 선택
    //출력
    if (minTime == inf) cout << -1;
    else cout << minTime;
    return 0;
}
