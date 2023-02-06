#include <iostream>
#include <queue>
using namespace std;

int n, m;
int year = 0;//녹는 시간
const int maxi = 301;
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 여부
int melt[maxi][maxi];//녹는 양
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            melt[i][j] = 0;
        }
    }
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//덩어리
int IsLump(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visit[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 여부
            if (world[nx][ny] < 1) continue;//빙산 높이

            visit[nx][ny] = true;//방문 체크
            q.push({ nx,ny });
        }
    }
    return 1;//덩어리 개수 1증가
}
//녹이기
void Melt() {
    //녹는 양 구하기
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            //빙산이 남아 있음
            if (world[i][j] > 0) {
                int cnt = 0;
                //동남서북 탐색
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k]; int nj = j + dy[k];
                    if (world[ni][nj] == 0) cnt++;
                }
                melt[i][j] = cnt;//녹는 양
            }
        }
    }
    //녹이기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) world[i][j] = max(0,world[i][j]-melt[i][j]);
    }
}
//전부 녹았는가?
bool isAllMelt() {
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (world[i][j] != 0) return false;//다 녹지 않음
        }
    }
    return true;
}
//진행
void Process() {
    while (true) {
        init();//초기화
        //전부 녹았는가?
        if (isAllMelt()) {
            year = 0;
            break;
        }
        //검사 시작하는 지점
        int Lump = 0;//덩어리 개수
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (world[i][j] == 0) continue;//물 지역
                if (!visit[i][j]) Lump += IsLump(i, j);//덩어리
            }
        }
        if (Lump >= 2) break;//2덩이 이상으로 분리
        Melt();//녹이기
        year++;//시간 증가
    }
    cout << year;//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Process();//진행 
    return 0;
}
