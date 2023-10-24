#include <iostream>
#include <vector>
using namespace std;

int r,c,t;
const int maxi = 51;
int world[maxi][maxi];//지도
int dust[maxi][maxi];//먼지 확산량
int maxAttack = 0;//최대 공격력
vector<pair<int, int>> cleaner;//청소기
//4방 탐색
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >>r>>c>>t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> world[i][j];
            if (world[i][j] == -1) cleaner.push_back({ i,j });
        }
    }
}
//초기화
void Init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) dust[i][j] = 0;
    }
}
//먼지 확산
void SpreadDust() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] <= 0) continue;

            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위 조건
                if (world[nx][ny] == -1) continue;//청정기

                cnt++;
                dust[nx][ny] += (world[i][j] / 5);
            }
            world[i][j] = world[i][j]-(world[i][j] / 5*cnt);
        }
    }
    //남은 양
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) world[i][j] += dust[i][j];
    }
}
//먼지양
int AmountDust() {
    int total = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] > 0) total += world[i][j];
        }
    }
    return total;
}
//청소
void Clean() {
    int checkPoint = cleaner[0].first;
    //반시계
    for (int i = checkPoint - 1; i > 0; i--) world[i][0] = world[i - 1][0];
    for (int j = 0; j < c - 1; j++) world[0][j] = world[0][j + 1];
    for (int i = 0; i < checkPoint; i++) world[i][c - 1] = world[i + 1][c - 1];
    for (int j = c - 1; j > 1; j--) world[checkPoint][j] = world[checkPoint][j - 1];
    world[checkPoint][1] = 0;
    //시계
    for (int i = checkPoint + 2; i < r - 1; i++) world[i][0] = world[i + 1][0];
    for (int j = 0; j < c - 1; j++)world[r - 1][j] = world[r - 1][j + 1];
    for (int i = r - 1; i > checkPoint + 1; i--) world[i][c - 1] = world[i-1][c - 1];
    for (int j = c - 1; j > 1; j--) world[checkPoint + 1][j] = world[checkPoint + 1][j - 1];
    world[checkPoint + 1][1] = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (t--) {
        Init();//초기화
        SpreadDust();//먼지 확산
        Clean();//청소
    }
    cout<<AmountDust();//먼지 양
    return 0;
}
