#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
const int maxi = 6;
bool isAllStudent = false;
char world[maxi][maxi];//월드
vector<pair<int,int>> teacher;//교사
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >>n;
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 'T') teacher.push_back({ i,j });
        }
    }
}
//감시
bool Seek() {
    //각 교사마다
    for (int k = 0; k < teacher.size(); k++) {
        int x = teacher[k].first;
        int y = teacher[k].second;

        //학생을 찾는다.
        for (int dir = 0; dir < 4; dir++) {//방향 정하기
            int xpos = x; int ypos = y;//위치 초기화
            while (true) {
                xpos += dx[dir]; ypos += dy[dir];
                if (xpos < 0 || xpos >= n || ypos < 0 || ypos >= n) break;//범위 초과
                if (world[xpos][ypos] == 'O') break;//장애물
                if (world[xpos][ypos] == 'S') return true;//학생발견
            }
        }
    }
    return false;
}

//장애물 설치
void Install(int cnt) {
    if (cnt == 3) {
        if(!Seek()) isAllStudent = true;//안들킴
        return;
    }

    //다음 설치 지점
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == 'X') {//장애물 가능 위치
                world[i][j] = 'O';
                Install(cnt + 1);//다음 장애물
                world[i][j] = 'X';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Install(0);//장애물 설치
    if (isAllStudent) cout << "YES";
    else cout << "NO";
    return 0;
}
