#include <iostream>
using namespace std;

int n,m,r;
const int maxi = 101;
const int inf = 11111111;
int item[maxi];//아이템 개수
int dist[maxi][maxi];//i->j까지의 최단거리

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
}
//입력
void input() {
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;
        dist[b][a] = d;//양방향
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
//아이템 얻기
void GetItem() {
    int total = 0;
    for (int i = 1; i <= n; i++) {//시작 지점
        int getItem = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) getItem += item[j];//수색 범위 이내
        }
        total = max(total, getItem);
    }
    cout << total;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Floyd();//플로이드
    GetItem();//아이템 얻기
    return 0;
}
