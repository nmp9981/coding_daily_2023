#include <iostream>
using namespace std;

int r, c;
int ans = 1;
const int maxi = 21;
string board[maxi];//보드
bool visitAlpha[26];//각 알파벳 방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> board[i];
    visitAlpha[board[0][0] - 'A'] = true;//알파벳
}
//말 이동
void Move(int x,int y,int cnt) {
    ans = max(ans, cnt);//정답 갱신
    //다음 지점
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위 조건
        if (visitAlpha[board[nx][ny] - 'A'] == true) continue;//알파벳 중복 여부

        visitAlpha[board[nx][ny] - 'A'] = true;
        Move(nx, ny, cnt + 1);
        visitAlpha[board[nx][ny] - 'A'] = false;
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Move(0,0,1);//말 이동
    cout << ans;//출력
    return 0;
}
