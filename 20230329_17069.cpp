#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 33;
int world[maxi][maxi];//맵
ll pipe[3][maxi][maxi];//각 방향마다 파이프를 놓는 경우의 수

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> world[i][j];
    }
}
//파이프 배치
void PipePush() {
    //맨 윗줄
    for (int j = 2; j <= n; j++) {
        if (world[1][j]==1) break;
        pipe[0][1][j] = 1;
    }
    //파이프 배치
    for (int i = 2; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (world[i][j] == 1) continue;
            //가로
            if (world[i][j - 1] == 0) {
                pipe[0][i][j] = pipe[0][i][j - 1] + pipe[2][i][j - 1];
            }
            //세로
            if (world[i - 1][j] == 0) {
                pipe[1][i][j] = pipe[1][i - 1][j] + pipe[2][i - 1][j];
            }
            //대각선
            if (world[i - 1][j] == 0 && world[i][j - 1] == 0 && world[i - 1][j - 1] == 0) {
                pipe[2][i][j] = pipe[2][i - 1][j - 1] + pipe[1][i - 1][j-1] + pipe[0][i-1][j - 1];
            }
        }
    }
    cout << pipe[0][n][n] + pipe[1][n][n] + pipe[2][n][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    PipePush();//파이프 밀기
    return 0;
}
