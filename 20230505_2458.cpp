#include <iostream>
using namespace std;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
int n, m;
int cnt = 0;
const int maxi = 501;
const int inf = 555555555;
int dist[maxi][maxi];//거리
int heightCnt[maxi];//몇명을 알수 있는가?

//입력
void input() {
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
}

//초기화
void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
}
//플로이드
void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}
//키순서
void Height() {
    //각 행
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > 0 && dist[i][j] < inf) heightCnt[i] += 1;
        }
    }
    //각 열
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][j] > 0 && dist[i][j] < inf) heightCnt[j] += 1;
        }
    }
    //결과를 아는자
    for (int i = 1; i <= n; i++) {
        if (heightCnt[i] == n - 1) cnt++;
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Floyd();//플로이드
    Height();//키순서
    return 0;
}
