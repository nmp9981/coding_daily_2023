#include <iostream>
#include <vector>
using namespace std;

const int maxi = 9;
int board[maxi][maxi];//판
vector<pair<int, int>> blank;//빈 칸
int blankSize;//빈칸 크기

//입력
void input() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({ i,j });
        }
    }
    blankSize = blank.size();
}
//행
bool Row(int x, int y,int num) {
    for (int i = 0; i < maxi; i++) {
        if (num == board[i][y]) return false;//이미 같은 숫자 존재
    }
    return true;
}
//열
bool Col(int x, int y, int num) {
    for (int j = 0; j < maxi; j++) {
        if (num == board[x][j]) return false;//이미 같은 숫자 존재
    }
    return true;
}
//박스
bool Box(int x, int y, int num) {
    int st_x = (x / 3)*3; int st_y = (y / 3)*3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (num == board[st_x + i][st_y + j]) return false;
        }
    }
    return true;
}
//출력
void output() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) cout << board[i][j] << " ";
        cout << "\n";
    }
}
//풀기
void Solve(int idx) {
    if (idx == blankSize) {//모두 채움
        output();
        exit(0);
    }
    //1~9까지 넣어보기
    for (int n = 1; n <= maxi; n++) {
        int x = blank[idx].first;
        int y = blank[idx].second;
        if (!Row(x, y,n)) continue;
        if (!Col(x, y,n)) continue;
        if (!Box(x, y,n)) continue;

        board[x][y] = n;
        Solve(idx + 1);
        board[x][y] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Solve(0);//풀기
    return 0;
}
