#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 5;
int caseNum = 0;//경우의 수
string world[maxi];//교실
bool isSelected[25];//선택한 학생
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    for (int i = 0; i < maxi; i++) cin >> world[i];
}

//이다솜파?
bool isSom() {
    int somCnt = 0;
    for (int i = 0; i < 25; i++) {
        if (isSelected[i] == true) {//선택한 학생
            int row = i / 5;
            int col = i % 5;
            if (world[row][col] == 'S') somCnt++;//이다솜파
        }
    }
    //결과
    if (somCnt >= 4) return true;
    return false;
}
//연결 여부
bool isConnect() {
    //초기화
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) visit[i][j] = false;
    }

    //초기 지점
    queue<pair<int, int>> q;
    for (int i = 0; i < 25; i++) {
        if (isSelected[i]) {
            int row = i / 5;
            int col = i % 5;
            q.push({ row,col });
            visit[row][col] = true;
            break;
        }
    }

    //연결하기
    int connectCnt = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            int num = 5 * nx + ny;
            if (isSelected[num] == false) continue;//선택 안함

            visit[nx][ny] = true;
            q.push({ nx,ny });
            connectCnt++;
        }
    }
    //결과
    if (connectCnt == 7) return true;
    return false;
}
//선발
void Pick(int idx,int cnt) {
    //7명 모음
    if (cnt == 7) {
        if (isSom()) {//이다솜파?
            if (isConnect()) {//연결 여부
                caseNum++;
            }
        }
        return;
    }
    //사람 모으기
    for (int k = idx; k < 25; k++) {
        if (isSelected[k]) continue;//이미 선택
        isSelected[k] = true;
        Pick(k + 1, cnt + 1);//다음 인원
        isSelected[k] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Pick(0,0);//학생 선택
    cout << caseNum;//출력
    return 0;
}
