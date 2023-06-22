#include <iostream>
#include <queue>
#include <vector>
using namespace std;//이름공간 선언

int n, m,virusSize,blankSize,minTimes;
const int inf = 150000;
const int maxi = 51;
int oriWorld[maxi][maxi];//지도 원본
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 시간
vector<pair<int, int>> virus;//바이러스
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
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            world[i][j] = oriWorld[i][j];
            visit[i][j] = -1;
        }
    }
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> oriWorld[i][j];
            if (oriWorld[i][j] == 2) virus.push_back({ i,j });
            if (oriWorld[i][j] == 0) blankSize++;
        }
    }
    virusSize = virus.size();
    if (blankSize == 0) minTimes = 0;//이미 다 퍼짐
    else minTimes = inf;
}
//확산
int Spread() {
    int times = 0;//시간
    int blankCnt = blankSize;//빈칸 개수
    queue<pair<int, int>> q;
    //처음 활성화 바이러스
    for (int i = 0; i < m; i++) {
        int stX = activeVirus[i].first;
        int stY = activeVirus[i].second;
        visit[stX][stY] = 0;
        q.push({ stX,stY });
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            if (visit[nx][ny] != -1) continue;//방문 조건
            if (world[nx][ny] == 1) continue;//벽

            if (world[nx][ny] == 0) blankCnt--; //빈칸 제거
            q.push({ nx,ny });
            visit[nx][ny] = visit[x][y] + 1;
            times = max(visit[nx][ny], times);
            if (blankCnt == 0) return times;//모두 확산
        }
    }
    if (blankCnt > 0) return inf;
    return times;
}
//활성화 바이러스
void SelectVirus(int idx, int cnt) {
    if (cnt == m) {
        init();//초기화
        minTimes = min(minTimes, Spread());//확산
        return;
    }
    //다음 바이러스
    for (int i = idx; i < virusSize; i++) {
        int nx = virus[i].first;
        int ny = virus[i].second;
        activeVirus.push_back({ nx,ny });
        SelectVirus(i + 1, cnt + 1);
        activeVirus.pop_back();
    }
}
int main() {
    input();//입력
    SelectVirus(0,0);//활성화 바이러스
    //출력
    if (minTimes == inf) cout << -1;
    else cout << minTimes;
    return 0;
}
