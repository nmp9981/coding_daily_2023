#include <iostream>
using namespace std;

int n, m;
const int maxi = 5;
int board[maxi][maxi];//판
bool visit[maxi][maxi];//방문 여부
int maxAttack = 0;//최대 공격력
//4방 탐색
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };

//max
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
//무기 제작
void MakeWeapon(int r,int c,int attack) {
    if (c == m) {//다음 행
        r++;
        c = 0;
    }
    if (r == n) {//종료
        maxAttack = max(maxAttack, attack);
        return;
    }

    //4방 탐색
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;//범위 조건
        if (visit[nr][c] || visit[r][c] || visit[r][nc]) continue;//방문 여부
        int atk = 2 * board[r][c] + board[nr][c] + board[r][nc];
        
        visit[nr][c] = true;
        visit[r][c] = true;
        visit[r][nc] = true;
        MakeWeapon(r,c+1,attack+atk);

        visit[nr][c] = false;
        visit[r][c] = false;
        visit[r][nc] = false;

    }
    MakeWeapon(r, c + 1,attack);

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (n == 1 || m == 1) cout << 0;
    else {
        MakeWeapon(0, 0,0);
        cout << maxAttack;
    }
    return 0;
}
