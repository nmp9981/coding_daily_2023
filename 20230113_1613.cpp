#include <iostream>
using namespace std;

int n, m, s;
const int maxi = 401;
const int inf = 99999999;
int history[maxi][maxi];//역사 관계

//min
inline int min(int a, int b) {
    return a > b ? b : a;
}
//초기화
void init() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            if (i == j) history[i][j] = 0;
            else history[i][j] = inf;
        }
    }
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        history[a][b] = 1;
    }
}
//플로이드
void floyd() {
    for (int k=1; k <=n; k++) {//경유 지점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) history[i][j] = min(history[i][j], history[i][k] + history[k][j]);
        }
    }
    //역방향
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=n; j++) {
            //정방향이 존재
            if (history[i][j] > 0 && history[i][j] < inf) history[j][i] = (-1) * history[i][j];
        }
    }
}
//관계 구하기
void relation() {
    cin >> s;
    for (int i = 0; i<s; i++) {
        int x, y;
        cin >> x >> y;
        if (history[x][y] == inf || history[x][y]==0) cout << 0 << "\n";
        else if (history[x][y] > 0) cout << -1 << "\n";
        else if (history[x][y] < 0) cout << 1 << "\n";
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();//초기화
    input();//입력
    floyd();//플로이드
    relation();//관계 구하기
    return 0;
}
