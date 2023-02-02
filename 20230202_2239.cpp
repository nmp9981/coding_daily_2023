#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int zeroCnt;
const int maxi = 9;
int board[maxi][maxi];
vector<pair<int, int>> zero;//0인 칸 모음

//입력
void input() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) scanf("%1d", &board[i][j]);
    }
    //0인 칸
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            if (board[i][j] == 0) zero.push_back({ i,j });
        }
    }
    zeroCnt = zero.size();//빈칸 개수
}
//출력
void output() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) cout << board[i][j];
        cout << "\n";
    }
}
//가로
bool Row(int x,int num) {
    for (int j = 0; j < maxi; j++) {
        if (board[x][j] == num) return false;
    }
    return true;
}
//세로
bool Col(int y, int num) {
    for (int i = 0; i < maxi; i++) {
        if (board[i][y] == num) return false;
    }
    return true;
}
//상자
bool Box(int x, int y, int num) {
    int st_x = 3*(x / 3); int st_y = 3*(y / 3);//시작 지점
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[st_x + i][st_y + j] == num) return false;
        }
    }
    return true;
}
//풀이
void solve(int cnt) {
    //모두 채움
    if (zeroCnt == cnt) {
        output();
        exit(0);
    }
    //다음 숫자
    for (int k = 1; k <= 9; k++) {
        int x = zero[cnt].first;
        int y = zero[cnt].second;
        //가로, 세로, 대각선 조건
        if (Row(x, k) && Col(y, k) && Box(x, y, k)) {
            board[x][y] = k;
            solve(cnt + 1);
            board[x][y] = 0;
        }
    }
}
int main() {
    //빠른 입력
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    input();//입력
    solve(0);//풀이
    return 0;
}
