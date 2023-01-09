#include <iostream>
using namespace std;

int n;
double prob = 0.0;//최종 확률
const int maxi = 40;
int dir[4];//확률
int dx[4] = {0,0,1,-1};//이동
int dy[4] = {1,-1,0,0};
bool visit[maxi][maxi];//방문 여부

//입력
void input() {
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> dir[i];
    visit[20][20] = true;//맨 처음 위치
}

//로봇 이동
void Robot(int x, int y, int cnt, double p) {
    if (cnt == n) {//이동 완료
        prob += p;
        return;
    }
    //다음 지점
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visit[nx][ny] == true) continue;//이미 방문
        double nextP = (double)dir[i]/100;
        visit[nx][ny] = true;
        Robot(nx, ny, cnt + 1, p*nextP);
        visit[nx][ny] = false;
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Robot(20, 20, 0,1);//로봇 위치,이동 횟수,확률
    printf("%.9f",prob);//최종 확률
    return 0;
}
