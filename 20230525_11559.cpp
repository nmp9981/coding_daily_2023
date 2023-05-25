#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int Col = 6;
const int Row = 12;
string world[Row];//월드
bool visit[Row][Col];//방문 조건
bool isBoom = false;//터졌는가?
int cnt = 0;
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화
void init() {
    isBoom = false;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) visit[i][j] = false;
    }
}
//입력
void input() {
    for (int i = 0; i < Row; i++) cin >> world[i];
}
//연쇄반응
void Chain(int i,int j,char c) {
    queue<pair<int, int>>q;
    q.push({ i,j });
    vector<pair<int, int>> Puyo;//탐색한 푸요
    Puyo.push_back({ i,j });
    visit[i][j] = true;//방문 체크

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= Row || ny < 0 || ny >= Col) continue;//범위 조건
            if (world[nx][ny] != c) continue;//같은색인가?
            if (visit[nx][ny]) continue;//방문 조건

            Puyo.push_back({ nx,ny });
            q.push({ nx,ny });
            visit[nx][ny] = true;
        }
    }
    //4개 이상
    if (Puyo.size() >= 4) {//터짐
        isBoom = true;
        for (int k = 0; k < Puyo.size(); k++) world[Puyo[k].first][Puyo[k].second] = '.';
    }
}
//Puyo내리기
void DownPuyo() {
    for (int j = 0; j < Col; j++) {//각 열별로
        vector<char> newPuyo;
        for (int i = Row-1; i >= 0; i--) {//밑에서부터
            if (world[i][j] != '.') newPuyo.push_back(world[i][j]);
        }
        for (int i = Row - 1; i >= 0; i--) {//밑에서부터
            if (i >= Row-newPuyo.size()) world[i][j] = newPuyo[Row - 1 - i];
            else world[i][j] = '.';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while(true) {
        init();//초기화
        //Puyo 탐색
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                if (visit[i][j]) continue;//이미 방문
                if (world[i][j] != '.') Chain(i, j, world[i][j]);
            }
        }
        //연쇄여부
        if (!isBoom) break;
        else {
            DownPuyo();//Puyo 내리기
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
