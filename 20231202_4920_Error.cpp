#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, maxSum;
const int maxi = 101;
const int inf = 4000001;
int board[maxi][maxi];//보드 판
bool visit[maxi][maxi];//방문 여부
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
void Init() {
    maxSum = -inf;
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) board[i][j] = 0;
    }
}
//입력
void input() {
    cin >> n;
    if (n == 0) exit(0);//종료
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> board[i][j];
    }
}
//4칸 탐색
void Dfs4(int x,int y, int sum, int cnt) {
    if (cnt == 4) {//4칸 채움
        maxSum = max(maxSum, sum);
        return;
    }
    //다음 지점
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
        if (visit[nx][ny]) continue;//방문 여부
        
        visit[nx][ny] = true;
        Dfs4(nx, ny, sum + board[nx][ny], cnt + 1);
        visit[nx][ny] = false;
    }
}
//Ah 모양
int ShapeAh(int x, int y, int sum) {//중심 좌표
    int minNum = inf;
    int block4 = sum;
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
        cnt++;
        sum += board[nx][ny];
        minNum = min(minNum, board[nx][ny]);
    }
    //결과
    if (cnt <= 2) return -inf;//입력이 음수일 수 있다.
    if (cnt == 4) return sum - minNum;
    return sum;
}
//테트리스
void Tetris(){
    //4칸 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                visit[i][j] = true;
                Dfs4(i, j, board[i][j], 1);
                visit[i][j] = false;
            }
        }
    }
    //Ah모양
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) maxSum = max(maxSum, ShapeAh(i,j, board[i][j]));
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    while (true) {
        t++;//테스트 번호 증가
        Init();//초기화
        input();//입력
        Tetris();//테트리스
        cout << t << ". " << maxSum << "\n";//출력
    }
    return 0;
}
