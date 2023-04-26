#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FireBall_Info {
    int xpos,ypos,mass, speed, direction;
};
struct World_Info {
    int mass, speed, direction;
};
class FireBall {
private:
    int n, m, com;
    static const int maxi = 51;
    vector<FireBall_Info> FireList;//파이어볼 리스트
    vector<World_Info> world[maxi][maxi];//지도
    //8방 탐색
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
public:
    FireBall() {};
    void input();//입력
    void init();//초기화
    void Command();//명령
    void Move();//이동
    void Union();//합치기
    int RestMass();//남은 질량
};
//입력
void FireBall::input() {
    cin >> n>>m>>com;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        FireList.push_back({ r-1,c-1,m,s,d });
    }
}
//초기화
void FireBall::init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) world[i][j].clear();
    }
}
//이동
void FireBall::Move() {
    for (int i = 0; i < FireList.size(); i++) {
        int dir = FireList[i].direction;
        int nx = (FireList[i].xpos + dx[dir] * (FireList[i].speed%n)+n)%n;
        int ny = (FireList[i].ypos + dy[dir] * (FireList[i].speed%n)+n)%n;
        world[nx][ny].push_back({ FireList[i].mass,FireList[i].speed,dir });
    }
}
//합치기
void FireBall::Union() {
    FireList.clear();//목록 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //파이어 볼이 2개 이상
            if (world[i][j].size() >= 2) {
                int totalMass = 0;
                int totalSpeed = 0;
                int oddCnt = 0;//홀수 개수
                int evenCnt = 0;//짝수 개수

                //질량, 속력의 합
                for (int k = 0; k < world[i][j].size(); k++) {
                    totalMass += world[i][j][k].mass;
                    totalSpeed += world[i][j][k].speed;
                    if (world[i][j][k].direction % 2 == 1) oddCnt++;
                    else evenCnt++;
                }
                int newMass = totalMass / 5;//새로운 질량
                int newSpeed = totalSpeed / world[i][j].size();//새로운 속력

                if (newMass == 0) continue;//질량이 0이면 소멸

                //새로 목록 넣기
                if (oddCnt == 0 || evenCnt == 0) {
                    for (int dir = 0; dir < 4; dir++) {
                        FireList.push_back({ i,j,newMass,newSpeed,2 * dir });
                    }
                }
                else {
                    for (int dir = 0; dir < 4; dir++) {
                        FireList.push_back({ i,j,newMass,newSpeed,2 * dir+1 });
                    }
                }
            }
            else if (world[i][j].size() == 1) {//파이어 볼 1개
                FireList.push_back({ i,j,world[i][j][0].mass,world[i][j][0].speed,world[i][j][0].direction });
            }
        }
    }
}
//명령
void FireBall::Command() {
    while (com--) {
        init();//초기화
        Move();//이동
        Union();//합치기
    }
}
//남은 질량의 합
int FireBall::RestMass() {
    int total = 0;
    for (int i = 0; i < FireList.size(); i++) total += FireList[i].mass;
    return total;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    FireBall fireBall;
    fireBall.input();//입력
    fireBall.Command();//명령
    cout << fireBall.RestMass();//남은 질량
    return 0;
}
