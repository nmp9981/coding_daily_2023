#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 51;
const int inf = 51 * 51 * 51;
int minTime;//최소 시간
int virusSize;//바이러스 총 개수
int blankCnt = 0;//빈칸 개수
int visit[maxi][maxi];//방문 시간
int world[maxi][maxi];//지도
int worldOri[maxi][maxi];//원본
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
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> worldOri[i][j];
            if (worldOri[i][j] == 0) blankCnt++;//빈칸 개수
            if (worldOri[i][j] == 2) virus.push_back({ i,j });//바이러스
        }
    }
    minTime = inf;
    virusSize = virus.size();
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
//확산
int Spread() {
    queue<pair<int, int>> q;
    int restBlank = blankCnt;//남은 빈칸 수
    int times = 0;//확산 시간
    //활성화 바이러스 넣기
    for (int i = 0; i < m; i++) {
        int stX = activeVirus[i].first;
        int stY = activeVirus[i].second;
        q.push({ stX,stY });
        visit[stX][stY] = 0;
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

            if (world[nx][ny] == 0) {//빈칸
                restBlank--;
                world[nx][ny] = 2;
            }
            visit[nx][ny] = visit[x][y] + 1;
            times = max(times, visit[nx][ny]);
            q.push({ nx,ny });

            if (restBlank == 0) return times;//빈칸을 다 채움
        }
    }
    return inf;//빈칸을 다 채우지 못함
}
//활성화 바이러스 조합
void ActiveVirus(int cnt,int idx) {
    //바이러스를 모음
    if (cnt == m) {
        init();//초기화
        minTime = min(minTime, Spread());
        return;
    }
    //다음 바이러스
    for (int k = idx; k < virusSize; k++) {
        int nx = virus[k].first;
        int ny = virus[k].second;
        activeVirus.push_back({nx,ny});
        ActiveVirus(cnt + 1, k + 1);
        activeVirus.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (blankCnt == 0) minTime = 0;//이미 다 참
    else ActiveVirus(0, 0);//활성화 바이러스 
    //출력
    if (minTime >= inf) cout << -1;
    else cout << minTime;
    return 0;
}
