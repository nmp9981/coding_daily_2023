#include <iostream>
using namespace std;

int n,m;
const int maxi = 5;
int totalAttack = 0;//총 공격력
int board[maxi][maxi];//보드판
bool visit[maxi][maxi];//방문 여부
//동남서북
int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}
//무기 제작
void WeaponMake(int r,int c,int sum) {
    //다음 행
    if (c == m) {
        r++;
        c = 0;
    }
    //종료
    if (r == n) {
        totalAttack = max(sum, totalAttack);//갱신
        return;
    }
    //4가지 방향
    if (!visit[r][c]) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;//범위 조건
            //방문 여부
            if (visit[nr][c]) continue;
            if (visit[r][nc]) continue;

            //방문 체크
            visit[r][c] = true;
            visit[nr][c] = true;
            visit[r][nc] = true;

            int csum = 2 * board[r][c] + board[nr][c] + board[r][nc];
            WeaponMake(r, c + 1, sum+csum);

            //체크 해제
            visit[r][c] = false;
            visit[nr][c] = false;
            visit[r][nc] = false;
        }
    }
    WeaponMake(r, c + 1, sum);//못만들어도 다음으로
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (n == 1 || m == 1) cout << 0;
    else {
        WeaponMake(0, 0, 0);//무기 제작
        cout << totalAttack;//출력
    }
    return 0;
}
