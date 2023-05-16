#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

int n,l,r;
bool isMove;//그날 인구 이동 여부
const int maxi = 51;
int world[maxi][maxi];//각 나라 인구수
bool visit[maxi][maxi];//방문여부
vector<pair<int, int>> country;//연합하는 나라들
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void Input() {
    cin >> n>>l>>r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
}
//월드 세팅
void WorldSetting(int sum) {
    int newPeople = sum / country.size();
    if (country.size() >= 2) isMove = true;//인구이동 일어남

    for (int i = 0; i < country.size(); i++) {
        int x = country[i].first;
        int y = country[i].second;
        world[x][y] = newPeople;//새로운 인구로
    }
}
//연합
void Union(int i, int j) {
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push({ i,j });
    country.clear();
    country.push_back({ i,j });
    int sum = world[i][j];//인구 합
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 초과
            if (visit[nx][ny]) continue;//방문 조건
            //인구 차
            int diff = abs(world[x][y] - world[nx][ny]);
            if (diff >= l && diff <= r) {
                q.push({ nx,ny });
                country.push_back({ nx,ny });
                visit[nx][ny] = true;
                sum += world[nx][ny];
            }
        }
    }
    WorldSetting(sum);//월드 세팅
}
//인구 이동
void PeopleMove() {
    int day = 0;
    while (true) {
        memset(visit, 0, sizeof(visit));
        isMove = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) Union(i, j);//연합
            }
        }
        if (isMove == false) break;//인구 이동이 일어나지 않았으므로 종료
        day++;
    }
    cout << day;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    PeopleMove();//인구 이동
    return 0;
}
