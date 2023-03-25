#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 500;
int board[maxi][maxi];//보드
bool visit[maxi][maxi];//방문 여부
int ans = 0;
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

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
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}
//길이 4인것
void Depth4(int depth,int x,int y,int sum) {
    //도착
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }
    //다음 지점
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visit[nx][ny]) continue;
        visit[nx][ny] = true;
        Depth4(depth + 1, nx,ny, sum + board[nx][ny]);
        visit[nx][ny] = false;
    }
}
//시작지점
void Start() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                visit[i][j] = true;
                Depth4(1, i, j, board[i][j]);
                visit[i][j] = false;
            }
        }
    }
}
//ㅏ 모양 탐색
int Ah(int x,int y) {
    int sum = board[x][y];
    int minNum = 1001;
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위초과
        cnt++;
        minNum = min(minNum, board[nx][ny]);
        sum += board[nx][ny];
    }
    if (cnt == 3) return sum;
    else if (cnt == 4) return sum - minNum;
    return 0;
}
//ㅏ 모양
void AhStart() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) ans = max(ans,Ah(i, j));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Start();//시작지점
    AhStart();//ㅏ 모양
    cout << ans;//출력
    return 0;
}
