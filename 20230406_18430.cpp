#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
const int maxi = 5;
int Attack = 0;
int board[maxi][maxi];
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { 1,1 ,-1,-1};
int dy[4] = { 1,-1,-1,1 };

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}

//무기제작
void MakeWeapon(int x,int y,int sum) {
    //다음 행
    if (y == m) {
        y = 0;
        x++;
    }
    //끝까지 탐색 완료
    if (x == n) {
        Attack = max(Attack, sum);
        return;
    }
    //무기 제작
    if (!visit[x][y]) {
        for (int i = 0; i < 4; i++) {//다음 지점
            int nx = x + dx[i];
            int ny = y + dy[i];

            //범위 조건
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            //방문 조건
            if (visit[nx][y]) continue;
            if (visit[x][ny]) continue;

            visit[x][y] = true;
            visit[nx][y] = true;
            visit[x][ny] = true;

            int add = 2 * board[x][y] + board[nx][y] + board[x][ny];
            MakeWeapon(x , y+1, sum+add);

            visit[x][y] = false;
            visit[nx][y] = false;
            visit[x][ny] = false;
        }
    }
    MakeWeapon(x , y+1, sum);//다음 으로
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (n == 1 || m == 1) cout << 0;
    else {
        MakeWeapon(0, 0, 0);//무기 제작
        cout << Attack;//공격
    }
    return 0;
}
