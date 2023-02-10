#include <iostream>
#include <queue>
using namespace std;

int r,c;
int times = 0;//시간
const int maxi = 51;
string world[maxi];
bool kaktusVisit[maxi][maxi];//고슴도치 방문 여부
queue<pair<int, int>> wq;//물
queue<pair<int, int>> kq;//고슴도치
//4방 탐색
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//입력
void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> world[i];
    //물, 고슴도치 초기 위치
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] == 'S') {//고슴도치
                kq.push({ i,j });
                kaktusVisit[i][j] = true;
            }
            if (world[i][j] == '*') wq.push({ i,j });//물
        }
    }
}
//물
void Water() {
    int wqSize = wq.size();//이전 물의 위치
    for (int i = 0; i < wqSize;i++) {
        int x = wq.front().first;
        int y = wq.front().second;
        wq.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위조건
            if (world[nx][ny] == '.' || world[nx][ny]=='S') {//빈칸이거나 고슴도치 칸
                wq.push({ nx,ny });
                world[nx][ny] = '*';//물 채우기
            }
        }
    }
}
//고슴도치
void KaKtus() {
    int kqSize = kq.size();//이전 고슴도치 위치
    int canMove = 0;//이동 가능 지점
    for (int i = 0; i < kqSize; i++) {
        int x = kq.front().first;
        int y = kq.front().second;
        kq.pop();

        //도착
        if (world[x][y] == 'D') {
            cout << times;
            exit(0);
        }
        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위조건
            if (kaktusVisit[nx][ny] == true) continue;//방문조건
            if (world[nx][ny] == '.' || world[nx][ny] == 'D') {//빈칸이거나 비버의 굴
                kaktusVisit[nx][ny] = true;//방문체크
                canMove++;//이동 가능
                kq.push({ nx,ny });
            }
        }
    }
    if (canMove == 0) {//더 이상 이동가능한 칸이 없다 
        cout << "KAKTUS";
        exit(0);
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    while (true) {
        Water();//물
        KaKtus();//고슴도치
        times++;//시간 경과
    }
    return 0;
}
