#include <iostream>
#include <queue>
using namespace std;

int r,c;
int times = 0;
const int maxi = 51;
string world[maxi];//지도
bool isEnd = false;//종료
bool visit[maxi][maxi];//방문 여부
queue<pair<int, int>> water;//물
queue<pair<int, int>> Kaktus;//고슴도치
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin>>r>>c;
    for (int i = 0; i < r; i++) {
        cin >> world[i];
        for (int j = 0; j < c; j++) {
            if (world[i][j] == 'S') {//고슴도치
                visit[i][j] = true;
                Kaktus.push({ i,j });
            }
            if (world[i][j] == '*')water.push({ i,j });//물
        }
    }
}

//물 확장
void SpreadWater() {
    int waterSize = water.size();
    for (int i = 0; i < waterSize; i++) {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위조건
            if (world[nx][ny] == '*') continue;//이미 방문
            if (world[nx][ny] == 'S' || world[nx][ny] == '.') {//확산 가능
                world[nx][ny] = '*';
                water.push({ nx,ny });
            }
        }
    }
}

//이동
void Move() {
    int moveSize = Kaktus.size();

    if (moveSize == 0) {//이동 불가
        cout << "KAKTUS";
        isEnd = true;
    }
    for (int i = 0; i < moveSize; i++) {
        int x = Kaktus.front().first;
        int y = Kaktus.front().second;
        Kaktus.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위조건
            if (visit[nx][ny]) continue;//이미 방문
            if (world[nx][ny] == 'D' || world[nx][ny] == '.') {//확산 가능
                visit[nx][ny] = true;
                Kaktus.push({ nx,ny });
                //도착
                if (world[nx][ny] == 'D') {
                    cout << times;
                    isEnd = true;
                    return;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        times++;//시간 증가
        SpreadWater();//물 확장
        Move();//고슴도치 이동
        if (isEnd) break;//종료
    }
    return 0;
}
