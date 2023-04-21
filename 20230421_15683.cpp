#include <iostream>
#include <vector>
using namespace std;

struct CameraInfo {
    int x, y, num;
};
int n,m;
int cameraSize = 0;
int blindSpot = 65;//사각지대 개수
const int maxi = 8;
vector<vector<int>> office;//사무실
vector<CameraInfo> camera;//카메라
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//범위 초과
bool isOut(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}
//감시 영역
int AreaCount() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            line.push_back(a);
        }
        office.push_back(line);
    }
    //카메라 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (office[i][j] >= 1 && office[i][j] <= 5) camera.push_back({ i,j,office[i][j] });
        }
    }
    cameraSize = camera.size();
}
//영역표시
void AreaCheck(int x, int y, int dir) {
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (isOut(x, y)) break;//범위 초과
        if (office[x][y] == 6) break;//벽
        if (office[x][y] == 0) office[x][y] = 7;//감시
    }
}
//감시
void Monitoring(CameraInfo cctv,int dir) {
    switch (cctv.num) {
    case 1:
        AreaCheck(cctv.x, cctv.y, dir);
        break;
    case 2:
        AreaCheck(cctv.x, cctv.y, dir);
        AreaCheck(cctv.x, cctv.y, (dir + 2) % 4);
        break;
    case 3:
        AreaCheck(cctv.x, cctv.y, dir);
        AreaCheck(cctv.x, cctv.y, (dir + 1) % 4);
        break;
    case 4:
        AreaCheck(cctv.x, cctv.y, dir);
        AreaCheck(cctv.x, cctv.y, (dir + 1) % 4);
        AreaCheck(cctv.x, cctv.y, (dir + 3) % 4);
        break;
    case 5:
        AreaCheck(cctv.x, cctv.y, 0);
        AreaCheck(cctv.x, cctv.y, 1);
        AreaCheck(cctv.x, cctv.y, 2);
        AreaCheck(cctv.x, cctv.y, 3);
        break;
    }
}
//방향세팅
void SetDirection(int idx) {
    //감시완료
    if (idx == cameraSize) {
        blindSpot = min(blindSpot, AreaCount());
        return;
    }
    vector<vector<int>> CopyOffice = office;//현재 맵 저장

    //idx번 카메라 방향설정
    for (int i = 0; i < 4; i++) {
        Monitoring(camera[idx],i);//감시
        SetDirection(idx + 1);//다음 카메라
        office = CopyOffice;//감시해제
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SetDirection(0);//방향세팅
    cout << blindSpot;//출력
    return 0;
}
