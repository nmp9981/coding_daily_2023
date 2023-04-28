#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r,c;
const int maxi = 1001;
bool visit[maxi][maxi];//방문 여부
string world[maxi];//지도
queue<pair<int, int>> jihun;//지훈
queue<pair<int, int>> fire;//불
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> world[i];

    //초기위치
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] == 'J') {
                jihun.push({ i,j });
                visit[i][j] = true;
            }
            if (world[i][j] == 'F') fire.push({ i,j });
        }
    }
}
//탈출
void Escape() {
    int times = 0;//시간
    while (true) {
        //불
        int fireSize = fire.size();
        for (int i = 0; i < fireSize; i++) {
            int fireX = fire.front().first;
            int fireY = fire.front().second;
            fire.pop();

            //다음 지점
            for (int k = 0; k < 4; k++) {
                int nextFireX = fireX + dx[k];
                int nextFireY = fireY + dy[k];
                
                if (nextFireX < 0 || nextFireX >= r || nextFireY < 0 || nextFireY >= c) continue;//범위 초과
                if (world[nextFireX][nextFireY] == '.' || world[nextFireX][nextFireY] == 'J') {//불 확산
                    world[nextFireX][nextFireY] = 'F';
                    fire.push({ nextFireX,nextFireY });
                }
            }
        }

        //지훈
        int deathCount = 0;
        int jihunSize = jihun.size();
        for (int i = 0; i < jihunSize; i++) {
            int jihunX = jihun.front().first;
            int jihunY = jihun.front().second;
            jihun.pop();

            //탈출
            if (jihunX == 0 || jihunX == r - 1 || jihunY == 0 || jihunY == c - 1) {
                cout << times + 1;
                return;
            }
            //다음 지점
            for (int k = 0; k < 4; k++) {
                int nextJihunX = jihunX + dx[k];
                int nextJihunY = jihunY + dy[k];

                if (nextJihunX < 0 || nextJihunX >= r || nextJihunX < 0 || nextJihunY >= c) continue;//범위 조건
                if (visit[nextJihunX][nextJihunY]) continue;//방문 조건
                if (world[nextJihunX][nextJihunY] == '#' || world[nextJihunX][nextJihunY] == 'F') continue;//벽이나 불
                
                jihun.push({ nextJihunX,nextJihunY });
                visit[nextJihunX][nextJihunY] = true;
                deathCount++;
            }
        }
        //탈출 불가
        if (deathCount == 0) {
            cout << "IMPOSSIBLE";
            return;
        }
        times++;//시간 증가
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Escape();//탈출
    return 0;
}
