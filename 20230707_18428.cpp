#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 6;
int teacherSize;//교사 인원
bool isSuccess = false;//감시 성공여부
char world[maxi][maxi];//지도
vector<pair<int, int>> teacher;//교사
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 'T') teacher.push_back({ i,j });//교사 위치
        }
    }
    teacherSize = teacher.size();
}
//감시
bool Watch() {
    //각 교사별
    for (int t = 0; t < teacherSize; t++) {
        int x = teacher[t].first;
        int y = teacher[t].second;

        //4방 탐색
        for (int k = 0; k < 4; k++) {
            int nx = x; int ny = y;
            while (true) {
                nx += dx[k];
                ny += dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;//범위 초과
                if (world[nx][ny] == 'O') break;//장애물

                if (world[nx][ny] == 'S') return true;//감시 성공
            }
        }
    }
    return false;//못찾음
}

//장애물 설치
void InstallWall(int cnt) {
    if (cnt == 3) {
        if (!Watch()) isSuccess = true;//감시 성공여부
        return;
    }
    //다음 지점
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == 'X') {//빈칸
                world[i][j] = 'O';
                InstallWall(cnt + 1);
                world[i][j] = 'X';
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    InstallWall(0);//장애물 설치
    //출력
    if (isSuccess) cout << "YES";
    else cout << "NO";
    return 0;
}
