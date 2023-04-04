#include <iostream>
using namespace std;

int n, m;
const int maxi = 5;
int attack = 0;//공격력
bool visit[maxi][maxi];//방문 여부
int board[maxi][maxi];//보드판
//4방 탐색
int dx[4] = { 0,1,0,-1 };//행
int dy[4] = { 1,0,-1,0 };//열

//min
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}

//무기 중심 지점
void Center(int r,int c,int atk) {
    //도착
    if (r == n) {
        attack = max(atk, attack);//공격
        return;
    }
    //다음 행
    if (c == m) {
        r++;
        c = 0;
    }
    //다음 지점
    if (!visit[r][c]) {
        for (int i = 0; i < 4; i++) {
            int leftX = r + dx[i];
            int leftY = c + dy[i];
            int rightX = r + dx[(i + 1) % 4];
            int rightY = c + dy[(i + 1) % 4];

            //범위 조건
            if (leftX < 0 || leftX >= n || leftY < 0 || leftY >= m) continue;
            if (rightX < 0 || rightX >= n || rightY < 0 || rightY >= m) continue;

            //방문 조건
            if (visit[r][c]) continue;
            if (visit[leftX][leftY]) continue;
            if (visit[rightX][rightY]) continue;

            visit[r][c] = true;
            visit[leftX][leftY] = true;
            visit[rightX][rightY] = true;

            int str = 2 * board[r][c] + board[leftX][leftY] + board[rightX][rightY];
            Center(r, c + 1, atk + str);

            visit[r][c] = false;
            visit[leftX][leftY] = false;
            visit[rightX][rightY] = false;
        }
    }
    //없어도 다음으로
    Center(r, c + 1, atk);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    //결과
    if (n == 1 || m == 1) cout << 0;
    else {
        Center(0,0,0);//무기중심 지점
        cout << attack;
    }
    return 0;
}
