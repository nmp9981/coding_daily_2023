#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,l,r;
const int maxi = 51;
bool isMove = false;//인구 이동 여부
int world[maxi][maxi];//월드
bool visit[maxi][maxi];//방문 여부
int day = 0;
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화
void init() {
    isMove = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visit[i][j] = false;
    }
}
//입력
void input() {
    cin >> n >> l>>r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
}
//합치기
void Union(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visit[i][j] = true;
    vector<pair<int, int>> country;//연합하는 나라
    country.push_back({ i,j });
    int total = world[i][j];//총 연합 인구

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            
            int diff = abs(world[x][y] - world[nx][ny]);//인구 차이
            if (diff >= l && diff <= r) {
                visit[nx][ny] = true;
                q.push({ nx,ny });
                country.push_back({ nx,ny });
                total += world[nx][ny];
            }
        }
    }
    //인구 이동
    if (country.size() >= 2) {
        isMove = true;
        for (int k = 0; k < country.size(); k++) {
            int x = country[k].first;
            int y = country[k].second;
            world[x][y] = total / country.size();
        }
    }
}
//나라 탐색
void SearchCountry() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) Union(i, j);//합치기
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        init();//초기화
        SearchCountry();//나라 탐색
        if (isMove) day++;
        else {
            cout << day;
            break;
        }
    }
    return 0;
}
