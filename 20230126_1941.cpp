#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int caseNum = 0;//경우의 수
const int maxi = 5;
string classroom[maxi];//교실
bool visit[maxi][maxi];//방문 여부
bool selected[25];//여학생 선택
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//연결 되었는가?
bool isConnect() {
    //처음 지점
    int sx, sy;
    for (int i = 0; i < 25; i++) {
        if (selected[i] == true) {
            sx = i / 5;
            sy = i % 5;
            break;
        }
    }
    memset(visit, false, sizeof(visit));//초기화
    queue<pair<int, int>> q;
    q.push({ sx,sy });
    visit[sx][sy] = true;//방문 체크
    int woman = 1;//연결된 사람 수

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;//범위 조건
            if (visit[nx][ny] == true) continue;//방문 조건
            if (selected[5 * nx + ny] == false) continue;//미선택
            q.push({ nx,ny });
            visit[nx][ny] = true;
            woman++;
        }
    }
    //연결 성립 여부
    if (woman == 7) return true;
    return false;
}
//솜파인가?
bool isSom() {
    int som = 0;
    for (int i = 0; i < 25; i++) {
        if (selected[i] == true) {
            if (classroom[i / 5][i % 5] == 'S') som++;
        }
    }
    if (som >= 4) return true;
    return false;
}
//입력
void input() {
    for (int i = 0; i < maxi; i++) cin >> classroom[i];
}
//7명 선택
void select7(int idx, int cnt) {
    if (cnt == 7) {//모두 선택
        if (isConnect()) {//연결 되었는가?
            if (isSom()) caseNum++;//솜파인가?
        }
        return;
    }
    for (int i = idx; i < 25; i++) {
        if (selected[i] == false) {//미선택
            selected[i] = true;
            select7(i, cnt + 1);//다음 인원
            selected[i] = false;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    select7(0,0);//7명 선택
    cout << caseNum;//출력
    return 0;
}
