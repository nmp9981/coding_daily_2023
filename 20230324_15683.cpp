#include <iostream>
#include <vector>
using namespace std;

struct CCTV_Info {//cctv 정보
    int num,x, y;
};
int n,m;
const int maxi = 8;
vector<vector<int>> office;//사무실
vector<CCTV_Info> camera;//카메라
int safeArea = maxi*maxi+1;//안전 지대 개수
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int state; cin >> state;
            row.push_back(state);
            //카메라 넣기
            if (state >= 1 && state <= 5) camera.push_back({ state,i,j });
        }
        office.push_back(row);
    }
}
//안전지대 개수
int SafeArea() {
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] == 0) area++;
        }
    }
    return area;
}
//감시
void Watch(int nx,int ny,int dir) {
    while (1) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;//범위 초과
        if (office[nx][ny] == 6) break;//벽
        if (office[nx][ny] == 0) office[nx][ny] = 7;//감시
    }
}
//회전
void Rotation(CCTV_Info cctv, int dir) {
    switch (cctv.num) {
    case 1:
        Watch(cctv.x, cctv.y, dir);
        break;
    case 2:
        Watch(cctv.x, cctv.y, dir);
        Watch(cctv.x, cctv.y, (dir+2)%4);
        break;
    case 3:
        Watch(cctv.x, cctv.y, dir);
        Watch(cctv.x, cctv.y, (dir + 1) % 4);
        break;
    case 4:
        Watch(cctv.x, cctv.y, (dir+3)%4);
        Watch(cctv.x, cctv.y, dir% 4);
        Watch(cctv.x, cctv.y, (dir + 1) % 4);
        break;
    case 5:
        Watch(cctv.x, cctv.y, 0);
        Watch(cctv.x, cctv.y, 1);
        Watch(cctv.x, cctv.y, 2);
        Watch(cctv.x, cctv.y, 3);
        break;
    }
}

//카메라 탐색
void Search(int idx) {
    //모두 탐색
    if (idx == camera.size()) {
        safeArea = min(safeArea, SafeArea());
        return;
    }
    vector<vector<int>> officeCopy = office;//맵 복사
    //다음 방향
    for (int i = 0; i < 4; i++) {
        Rotation(camera[idx], i);
        Search(idx+1);
        office = officeCopy;//원래대로
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Search(0);//카메라 탐색
    cout << safeArea;//안전 지대 최대 개수
    return 0;
}
