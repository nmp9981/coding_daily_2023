#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 12;
bool isBoom;
string world[maxi];
bool visit[maxi][6];
//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    for (int i = 0; i < maxi; i++) cin >> world[i];
}
//초기화
void Init() {
    isBoom = false;
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < 6; j++) visit[i][j] = false;
    }
}
//4개이상이 연결되었는가?
void Grouping(int x,int y,char color) {
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ x,y });
    visit[x][y] = true;
    vector<pair<int, int>> group;//그룹
    group.push_back({ x,y });

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];

            if (nx < 0 || nx >= maxi || ny < 0 || ny >= 6) continue;//범위 초과
            if (visit[nx][ny]) continue;//이미 방문
            if (world[nx][ny] == color) {//같은 색
                visit[nx][ny] = true;
                group.push_back({ nx,ny });
                q.push({ nx,ny });
            }
        }
    }
    if (group.size() >= 4) {//없어짐
        isBoom = true;//연쇄가 일어남
        for (int k = 0; k < group.size(); k++) {
            int newX = group[k].first;
            int newY = group[k].second;
            world[newX][newY] = '.';
        }
    }
}
//탐색
void Search() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < 6; j++) {
            if (world[i][j] != '.' && !visit[i][j]) {
                Grouping(i, j, world[i][j]);//색 터뜨리기
            }
        }
    }
}
//중력
void Gravity() {
    for (int j = 0; j < 6;j++) {//각 세로줄 별로
        queue<char> element;//각 요소
        for (int i = maxi-1; i>=0; i--) {//밑에서부터 탐색
            if (world[i][j] != '.') element.push(world[i][j]);
        }
        //갱신
        int Ypos = maxi - 1;
        while (!element.empty()) {
            world[Ypos][j] = element.front();
            element.pop();
            Ypos--;
        }
        while (Ypos >= 0) {
            world[Ypos][j] = '.';
            Ypos--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    int cnt = 0;
    while (true) {
        Init();//초기화
        Search();//탐색
        if (!isBoom) break;//연쇄 X
        Gravity();//중력
        cnt++;//연쇄 횟수 증가
    }
    cout << cnt;
    return 0;
}
