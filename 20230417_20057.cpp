#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tornado {
private:
    int n;
    static const int maxi = 501;
    int world[maxi][maxi];
    
    //4방 탐색
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    //모래 이동량
    int sandX[4][10] = { {-1,1,-2,2,-1,1,-1,1,0,0},
        {-1,-1,0,0,0,0,1,1,2,1},
        {-1,1,-2,2,-1,1,-1,1,0,0},
        {1,1,0,0,0,0,-1,-1,-2,-1} };
    int sandY[4][10] = { {-1,-1,0,0,0,0,1,1,2,1},
        {-1,1,-2,2,-1,1,-1,1,0,0},
        {1,1,0,0,0,0,-1,-1,-2,-1},
        {-1,1,-2,2,-1,1,-1,1,0,0} };
    int Amount[10] = { 1,1,2,2,7,7,10,10,5,55 };
public:
    Tornado() {};//기본 생성자
    void input();//입력
    void Move();//이동
    int Flutter(int x, int y,int dir);//흩날리기
};

//입력
void Tornado::input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
}
//흩날리기
int Tornado::Flutter(int x, int y,int dir) {
    int outAmount = 0;
    int rest = world[x][y];//남은 모래의 양
    for (int i = 0; i < 10; i++) {
        int nx = x + sandX[dir][i];
        int ny = y + sandY[dir][i];
        int amount = world[x][y] * Amount[i] / 100;

        if (i == 9) amount = rest;//남은거 전부
        //맵 밖으로 나갔는가?
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) outAmount += amount;
        else world[nx][ny] += amount;

        rest -= amount;//남은 모래의 양
    }
    world[x][y] = 0;//모래가 남지 않음
    return outAmount;
}
//이동
void Tornado::Move() {
    int x = n / 2; int y = n / 2;//위치
    int len = 0;//이동 거리
    int dir = 2;//방향
    int outTotal = 0;//나간 총 모래의 양

    while (true) {
        if (dir % 2 == 0) len++;//이동 거리 증가

        for (int i = 0; i < len; i++) {
            x += dx[dir];
            y += dy[dir];

            outTotal += Flutter(x, y,dir);//흩날리기
            //종료
            if (x == 0 && y == 0) {
                cout << outTotal;
                return;
            }
        }
        dir = (dir + 3) % 4;//반시계
    }
    cout << outTotal;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Tornado tornado;
    tornado.input();//입력
    tornado.Move();//이동
    return 0;
}
