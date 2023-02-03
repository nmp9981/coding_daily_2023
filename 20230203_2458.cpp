#include <iostream>
using namespace std;

int n,m;
const int maxi = 501;
const int inf = 80000000;
int dist[maxi][maxi];
int height[maxi];//키 순서

//min
int inline min(int x, int y) {
    return x > y ? y : x;
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
//입력
void input() {
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
}
//플로이드
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
//검사
void inspect() {
    //행검사(본인보다 더 큰 사람의 수)
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != inf && dist[i][j] != 0) cnt++;
        }
        height[i] = cnt;
    }
    //열검사(본인보다 더 작은 사람의 수)
    for (int j = 1; j <= n; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i][j] != inf && dist[i][j] != 0) cnt++;
        }
        height[j] += cnt;
    }
    //합이 n-1이면 본인이 몇번째인지 알 수 있다.
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (height[i] == n - 1) ans++;
    }
    cout << ans;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();//초기화
    input();//입력
    floyd();//플로이드 알고리즘
    inspect();//검사
    return 0;
}
