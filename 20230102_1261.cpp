#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//벽
struct wall {
    int x, y;//위치
};

int m,n;
const int maxi = 101;
const int inf = 100000;
string maze[maxi];//미로
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visit[maxi][maxi];//(i,j)에서 벽을 몇개 부쉈는가

//입력
void input() {
    cin >> m>>n;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) visit[i][j] = inf;
    }
}
//미로 이동
void Move() {
    queue<wall> q;
    q.push({ 0,0});
    visit[0][0] = 0;
    
    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위조건
            
            //빈공간
            if (maze[nx][ny]=='0') {
                if (visit[nx][ny] > visit[cx][cy]) {
                    visit[nx][ny] = visit[cx][cy];
                    q.push({ nx,ny });
                }
            }
            //벽
            if (maze[nx][ny] == '1') {
                if (visit[nx][ny] > visit[cx][cy]+1) {
                    visit[nx][ny] = visit[cx][cy] + 1;
                    q.push({ nx,ny});
                }
            }
        }
    }
    cout << visit[n - 1][m - 1];//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Move();//이동하기
    return 0;
}
