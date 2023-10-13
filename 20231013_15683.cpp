#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//카메라
struct Cam {
    int type, x, y;
};
int n, m;
const int maxi = 8;
int area = 65;//영역 수
//int world[maxi][maxi];//지도
int setWorld[maxi][maxi];//원래 지도
vector<vector<int>> world;
vector<Cam> Camera;//카메라
int cameraSize;
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i <n; i++) {
        vector<int> line;
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            line.push_back(a);
        }
        world.push_back(line);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] <= 5 && world[i][j] >= 1) Camera.push_back({ world[i][j],i,j });//카메라 등록
        }
    }
    cameraSize = Camera.size();
}
//감시 중
void CamActive(int dir, int x, int y) {
    while (true) {
        x += dx[dir]; y += dy[dir];//다음 지점
        if (x < 0 || x >= n || y < 0 || y >= m) break;//범위 초과
        if (world[x][y] == 6) break;//벽
        if (world[x][y] == 0) world[x][y] = 7;//감시 표시
    }
}
//감시
void Monitoring(int dir, Cam cam) {
    switch (cam.type) {
    case 1:
        CamActive(dir, cam.x, cam.y);
        break;
    case 2:
        CamActive(dir, cam.x, cam.y);
        CamActive((dir+2)%4, cam.x, cam.y);
        break;
    case 3:
        CamActive(dir, cam.x, cam.y);
        CamActive((dir + 1) % 4, cam.x, cam.y);
        break;
    case 4:
        CamActive(dir, cam.x, cam.y);
        CamActive((dir + 1) % 4, cam.x, cam.y);
        CamActive((dir + 3) % 4, cam.x, cam.y);
        break;
    case 5:
        CamActive(0, cam.x, cam.y);
        CamActive(1, cam.x, cam.y);
        CamActive(2, cam.x, cam.y);
        CamActive(3, cam.x, cam.y);
        break;
    }
}
//원래대로
void Offset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) world[i][j] = setWorld[i][j];
    }
}
//감시 영역
int AreaCount() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
//탐색
void Search(int idx) {
    //사각지대 세기
    if (idx == cameraSize) {
        area = min(area,AreaCount());
        return;
    }

    vector<vector<int>> copyWorld = world;

    //방향 설정
    for (int dir = 0; dir < 4; dir++) {
        Monitoring(dir, Camera[idx]);//감시
        Search(idx + 1);//다음 카메라
        world = copyWorld;//원래대로
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Search(0);//탐색
    cout << area;//출력
    return 0;
}
