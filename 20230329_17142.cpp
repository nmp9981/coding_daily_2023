#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
const int maxi = 51;
const int inf = 10000000;
int virusSize;
int minTime = inf;//최소 시간
int world[maxi][maxi];//연구소
int visit[maxi][maxi];//방문 시간
vector<pair<int, int>> virus;//바이러스
vector<pair<int, int>> selectVirus;//선택한 바이러스
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x < y ? x : y;
}

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 2) virus.push_back({ i,j });
        }
    }
    virusSize = virus.size();
}
//확산
int Spread() {
    memset(visit, -1, sizeof(visit));//초기화

    queue < pair<int, int>> q;
    //바이러스 넣기
    for (int i = 0; i < selectVirus.size(); i++) {
        q.push({ selectVirus[i].first,selectVirus[i].second });
        visit[selectVirus[i].first][selectVirus[i].second] = 0;
    }

    //확산
    int times = 0;
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
            if (world[nx][ny] == 1) continue;//장애물

            visit[nx][ny] = visit[x][y] + 1;
            if (world[nx][ny] == 0) times = visit[nx][ny];//빈 공간에서만 시간을 센다
            q.push({ nx,ny });
        }
    }
    //확인
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //벽이 아닌데 미방문 지점이 있다.
            if (world[i][j] != 1 && visit[i][j] == -1) times = inf;
        }
    }
    return times;
}
//바이러스 선택
void SelectVirus(int cnt,int idx) {
    if (cnt == m) {
        minTime = min(minTime,Spread());//확산
        return;
    }
    for (int i = idx; i < virusSize; i++) {
        selectVirus.push_back({ virus[i].first ,virus[i].second });
        SelectVirus(cnt + 1, i + 1);
        selectVirus.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SelectVirus(0,0);//선택한 바이러스
    //출력
    if (minTime == inf) cout << -1;
    else cout << minTime;
    return 0;
}
