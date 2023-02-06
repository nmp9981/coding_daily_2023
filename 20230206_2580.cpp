#include <iostream>
#include <vector>
using namespace std;

int blankSize;//빈칸 개수
const int maxi = 9;
int sudoku[maxi][maxi];//스도쿠
vector<pair<int, int>> blank;//빈칸 위치

//입력
void input() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) blank.push_back({ i,j });
        }
    }
    blankSize = blank.size();//빈칸 개수
}
//출력
void output() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) cout << sudoku[i][j] << " ";
        cout << "\n";
    }
}
//행 검사
bool Row(int x, int n) {
    for (int j = 0; j < maxi; j++) {
        if (sudoku[x][j] == n) return false;//이미 존재
    }
    return true;
}
//열 검사
bool Col(int y, int n) {
    for (int i = 0; i < maxi; i++) {
        if (sudoku[i][y] == n) return false;//이미 존재
    }
    return true;
}
//상자 검사
bool Box(int x, int y, int n) {
    int st_x = 3*(x / 3);
    int st_y = 3*(y / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[st_x + i][st_y + j] == n) return false;//이미 존재
        }
    }
    return true;
}
//풀이
void Solve(int idx) {
    //모두 채움
    if (idx == blankSize) {
        output();
        exit(0);
    }
    //다음 숫자
    for (int k = 1; k <= 9; k++) {
        int x = blank[idx].first;//위치
        int y = blank[idx].second;
        if (!Row(x, k)) continue;//행 검사
        if (!Col(y, k)) continue;//열 검사
        if (!Box(x, y, k)) continue;//박스 검사

        sudoku[x][y] = k;//숫자 적기
        Solve(idx + 1);//다음 빈칸 채우기
        sudoku[x][y] = 0;//백트래킹
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Solve(0);//풀이 
    return 0;
}
