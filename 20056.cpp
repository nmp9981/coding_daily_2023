#include <iostream>
#include <vector>
using namespace std;

//파이어볼
struct FireBall_Info {
    int rpos, cpos, mass, speed, direction;
};
//맵 정보
struct World_Info {
    int mass, speed, direction;
};
int n,m,k;
const int maxi = 51;
vector<World_Info> world[maxi][maxi];
vector<FireBall_Info> FireBall;
//8방 탐색
int dr[8] = { -1,-1 ,0,1,1,1,0,-1};
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };

//입력
void input() {
    cin >> n>>m>>k;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        FireBall.push_back({ r-1,c-1,m,s,d });
    }
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) world[i][j].clear();
    }
}
//이동
void Move() {
    for (int i = 0; i < FireBall.size(); i++) {
        int moveSpeed = FireBall[i].speed;
        int moveDir = FireBall[i].direction;
        //끝과 끝은 연결
        int nr = (FireBall[i].rpos + (moveSpeed % n) * dr[moveDir] + n) % n;
        int nc = (FireBall[i].cpos + (moveSpeed % n) * dc[moveDir] + n) % n;

        world[nr][nc].push_back({FireBall[i].mass,moveSpeed,moveDir });
    }
}
//파이어볼 나누기
void Divide() {
    FireBall.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j].size() >= 2) {//2개 이상
                int totalMass = 0;
                int totalSpeed = 0;
                int odd = 0;
                int even = 0;

                //합치기
                for (int x = 0; x < world[i][j].size(); x++) {
                    totalMass += world[i][j][x].mass;
                    totalSpeed += world[i][j][x].speed;
                    if (world[i][j][x].direction % 2 == 0) even++;//짝수
                    else odd++;//홀수
                }
                //분리
                int newMass = totalMass / 5;
                int newSpeed = totalSpeed / world[i][j].size();
               
                //질량이 0이 아니면 새로운 파이어볼
                if (newMass > 0) {
                    if (even == 0 || odd == 0) {//모두 홀수 or 모두 짝수
                        FireBall.push_back({ i,j,newMass,newSpeed,0 });
                        FireBall.push_back({ i,j,newMass,newSpeed,2 });
                        FireBall.push_back({ i,j,newMass,newSpeed,4 });
                        FireBall.push_back({ i,j,newMass,newSpeed,6 });
                    }
                    else {
                        FireBall.push_back({ i,j,newMass,newSpeed,1 });
                        FireBall.push_back({ i,j,newMass,newSpeed,3 });
                        FireBall.push_back({ i,j,newMass,newSpeed,5 });
                        FireBall.push_back({ i,j,newMass,newSpeed,7 });
                    }
                }
            }
            else if (world[i][j].size() == 1) FireBall.push_back({ i,j,world[i][j][0].mass,world[i][j][0].speed,world[i][j][0].direction });
        }
    }
}
//남아있는 질량
int RestMass() {
    int restMass = 0;
    for (int i = 0; i < FireBall.size(); i++) restMass += FireBall[i].mass;
    return restMass;
}
//명령
void Command() {
    while(k--) {
        init();//초기화
        Move();//이동
        Divide();//파이어볼 나누기   
    }
    cout << RestMass();//남아있는 질량
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Command();//명령
    return 0;
}
