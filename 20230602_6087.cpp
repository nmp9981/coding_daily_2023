#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//위치 정보
struct Pos {
    int x, y;//좌표
};

int w,h;
const int maxi = 101;
const int inf = 100001;
string world[maxi];//월드
int mirrorCnt[maxi][maxi];//거울 설치 개수
bool visit[maxi][maxi];//방문 여부
vector<pair<int, int>> mirror;//거울
//동남서북
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//초기화
void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            visit[i][j] = false;
            mirrorCnt[i][j] = 0;
        }
    }
}
//입력
void input() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> world[i];
        for (int j = 0; j < w; j++) {
            if (world[i][j] == 'C') mirror.push_back({ i,j });//거울 위치
        }
    }
}
//레이저
void Layzer() {
    //초기 레이저
    queue<Pos> q;
    q.push({ mirror[0].first,mirror[0].second });
    visit[mirror[0].first][mirror[0].second] = 0;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        //다음 지점
        for (int ndir = 0; ndir < 4; ndir++) {
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            
            while (true) {
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) break;//범위 조건
                if (world[nx][ny] == '*') break;//벽

                if (mirrorCnt[nx][ny] == 0) {//아직 안감
                    mirrorCnt[nx][ny] = mirrorCnt[x][y] + 1;
                    q.push({ nx,ny });
                }
                nx += dx[ndir];
                ny += dy[ndir];
            }
        }
    }
    cout << mirrorCnt[mirror[1].first][mirror[1].second]-1;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    init();//초기화
    Layzer();//레이저
    return 0;
}
