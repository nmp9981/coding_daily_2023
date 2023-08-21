#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r,c;
int moveCnt = 1;
const int maxi = 21;
string world[maxi];
bool visitAlpha[26];//지나간 알파벳
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin>>r>>c;
    for (int i = 0; i < r; i++) cin >> world[i];
    visitAlpha[world[0][0] - 'A'] = true;
}
//말 이동
void Move(int x,int y,int depth) {
    //최대 이동 칸수
    moveCnt = max(moveCnt, depth);
    //다음 지점
    for (int i = 0; i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위 조건
        if (visitAlpha[world[nx][ny] - 'A']) continue;//이미 방문
        visitAlpha[world[nx][ny] - 'A'] = true;
        Move(nx, ny, depth + 1);
        visitAlpha[world[nx][ny] - 'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move(0,0,1);//말 이동
    cout << moveCnt;
    return 0;
}
