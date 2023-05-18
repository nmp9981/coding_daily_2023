#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,storeSize;
int startX, startY, endX, endY;
const int maxi = 102;
vector<pair<int, int>> store;//편의점
bool visit[maxi];//방문 여부

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    store.clear();//초기화
    for (int i = 0; i < maxi; i++) visit[i] = false;
}
//입력
void Input() {
    cin >> n;
    cin >> startX >> startY;//시작점
    for (int i = 0; i < n; i++) {//편의점
        int x, y;
        cin >> x >> y;
        store.push_back({ x,y });
    }
    cin >> endX >> endY;//도착점
    store.push_back({ endX,endY });
    storeSize = store.size();
}
//맨해튼
int Manhatten(int x,int y,int nx, int ny) {
    return abs(x - nx) + abs(y - ny);
}
//이동
void Move() {
    queue<pair<int, int>> q;
    q.push({ startX,startY });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //도착
        if (x == endX && y == endY) {
            cout << "happy\n";
            return;
        }
        //다음 지점
        for (int i = 0; i <storeSize; i++) {
            if (visit[i]) continue;//이미 방문

            int nx = store[i].first;
            int ny = store[i].second;
            int dist = Manhatten(x,y,nx, ny);
            if (dist <= 1000) {//거리 조건
                visit[i] = true;
                q.push({ nx,ny });
            }
        }
    }
    cout << "sad\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;cin >> t;
    while (t--) {
        init();//초기화
        Input();//입력
        Move();//이동
    }
    return 0;
}
