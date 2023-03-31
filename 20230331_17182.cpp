#include <iostream>
#include <vector>
using namespace std;

int n,k;
const int maxi = 11;
const int inf = 123454321;
int planet[maxi][maxi];//행성
int times[maxi][maxi];//탐사 소요 시간
bool isVisit[maxi];//방문 여부
int minTime = inf;//최소 시간

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> planet[i][j];
            if (i == j) times[i][j] = 0;
            else times[i][j] = inf;
        }
    }
    isVisit[k] = true;
}
//플로이드
void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) times[i][j] = min(times[i][j], planet[i][k] + planet[k][j]);
        }
    }
}
//탐사
void Explore(int pos,int cnt,int dist) {
    //모두 탐사
    if (cnt == n) {
        minTime = min(minTime, dist);
        return;
    }
    //다음 지점
    for (int i = 0; i < n; i++) {
        if (pos == i) continue;
        if (isVisit[i]) continue;
        isVisit[i] = true;
        Explore(i, cnt + 1, dist + times[pos][i]);
        isVisit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Floyd();//플로이드
    Explore(k,1,0);//탐사
    cout << minTime;//출력
    return 0;
}
