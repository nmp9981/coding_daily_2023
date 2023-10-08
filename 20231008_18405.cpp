#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,k,S,X,Y;
const int maxi = 201;
int world[maxi][maxi];
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
    cin >> S >> X >> Y;
}

//확산
void Spread() {
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(world[i][j]!=0) pq.push({ -world[i][j], {i,j} });
        }
    }
    
    int times = 0;
    while (times<S) {
        int pqSize = pq.size();
        vector<pair<int, pair<int, int>>> newPos;

        for (int i = 0; i < pqSize; i++) {
            int type = pq.top().first;//-1
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위조건
                if (world[nx][ny] != 0) continue;//전염됨

                world[nx][ny] = -type;
                newPos.push_back({ type,{nx,ny} });
            }
        }
        int newSize = newPos.size();
        for (int k = 0; k < newSize; k++) {
            pq.push({ newPos[k].first,{newPos[k].second.first,newPos[k].second.second} });
        }
        times++;
    }
    cout << world[X-1][Y-1];//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Spread();//확산
    return 0;
}
