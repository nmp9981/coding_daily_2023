#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//코인 위치 정보
struct CoinPos {
    int x0, y0, x1, y1,Count;
};
int n,m;
const int maxi = 22;
vector<pair<int, int>> firstState;//처음 상태
char board[maxi][maxi];//보드판
bool fisrtVisit[maxi][maxi];//첫번째 동전 방문 여부
bool secondVisit[maxi][maxi];//두번째 동전 방문 여부
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
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) board[i][j] = '.';
    }
}
//입력
void input() {
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) {
            board[i][j] = s[j - 1];
            if (board[i][j] == 'o') firstState.push_back({ i,j });
        }
    }
}
//범위 검사
bool isRange(int x, int y) {
    if (x <= 0 || x > n || y <= 0 || y > m) return false;
    return true;
}
//버튼
void Button() {
    queue<CoinPos> q;
    q.push({ firstState[0].first,firstState[0].second,firstState[1].first,firstState[1].second,0 });

    while (!q.empty()) {
        int fx = q.front().x0;
        int fy = q.front().y0;
        int sx = q.front().x1;
        int sy = q.front().y1;
        int cnt = q.front().Count;
        q.pop();

        //횟수 초과
        if (cnt > 10) {
            cout << -1;
            return;
        }
        //도착
        if ((isRange(fx, fy) && !isRange(sx, sy)) || (!isRange(fx, fy) && isRange(sx, sy))) {
            cout<<cnt;
            return;
        }
        
        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nfx = fx + dx[k];
            int nfy = fy + dy[k];
            int nsx = sx + dx[k];
            int nsy = sy + dy[k];

            if (!isRange(nfx, nfy) && !isRange(nsx, nsy)) continue;//둘다 떨어짐

            //벽
            if (board[nfx][nfy] == '#') {
                nfx = fx;
                nfy = fy;
            }
            if (board[nsx][nsy] == '#') {
                nsx = sx;
                nsy = sy;
            }
            q.push({ nfx,nfy,nsx,nsy,cnt + 1 });
        }
    }
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    Button();//버튼
    return 0;
}
