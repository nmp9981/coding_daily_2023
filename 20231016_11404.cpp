#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
const int maxi = 101;
const int inf = 10000001;
int dist[maxi][maxi];//거리
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//초기화
void Init() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
}
//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i <m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
    }
}

//플로이드
void Floyd() {
    for (int k = 1; k <= n; k++) {//경유지점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Init();//초기화
    input();//입력
    Floyd();//플로이드
    return 0;
}
