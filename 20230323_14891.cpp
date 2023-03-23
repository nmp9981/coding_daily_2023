#include <iostream>
#include <cstring>
using namespace std;

int n,k,r;
const int maxi = 5;
string wheel[maxi];//톰니바퀴

//회전
void Rotation(int n, int r) {
    string newWheel = "";//새로운 회전
    if (r == 1) {//시계
        newWheel = wheel[n][7] + wheel[n].substr(0, 7);
    }
    else if (r == -1) {//반시계
        newWheel = wheel[n].substr(1, 8) + wheel[n][0];
    }
    wheel[n] = newWheel;//갱신
}
//극 검사
void Pole(int n,int r) {
    switch (n) {
    case 1:
        if (wheel[1][2] != wheel[2][6]) {
            if (wheel[2][2] != wheel[3][6]) {
                if (wheel[3][2] != wheel[4][6]) {
                    Rotation(1, r);
                    Rotation(2, -r);
                    Rotation(3, r);
                    Rotation(4, -r);
                }
                else {
                    Rotation(1, r);
                    Rotation(2, -r);
                    Rotation(3, r);
                }
            }
            else {
                Rotation(1, r);
                Rotation(2, -r);
            }
        }
        else Rotation(1, r);
        break;
    case 2:
        if (wheel[2][6] == wheel[1][2] && wheel[2][2] == wheel[3][6]) {//양쪽다 막힘
            Rotation(2, r);
        }
        else if (wheel[2][6] != wheel[1][2] && wheel[2][2] == wheel[3][6]) {//왼쪽만 가능
            Rotation(2, r);
            Rotation(1, -r);
        }
        else if (wheel[2][6] == wheel[1][2] && wheel[2][2] != wheel[3][6]) {//오른쪽만 가능
            if (wheel[3][2] == wheel[4][6]) {//막힘
                Rotation(2, r);
                Rotation(3, -r);
            }
            else if(wheel[3][2] != wheel[4][6]) {//회전
                Rotation(2, r);
                Rotation(3, -r);
                Rotation(4, r);
            }
        }
        else if (wheel[2][6] != wheel[1][2] && wheel[2][2] != wheel[3][6]) {//양쪽
            if (wheel[3][2] == wheel[4][6]) {//막힘
                Rotation(1, -r);
                Rotation(2, r);
                Rotation(3, -r);
            }
            else if(wheel[3][2] != wheel[4][6]){//회전
                Rotation(1, -r);
                Rotation(2, r);
                Rotation(3, -r);
                Rotation(4, r);
            }
        }
        break;
    case 3:
        if (wheel[3][6] == wheel[2][2] && wheel[3][2] == wheel[4][6]) {//양쪽다 막힘
            Rotation(3, r);
        }
        else if (wheel[3][6] == wheel[2][2] && wheel[3][2] != wheel[4][6]) {//오른쪽만 가능
            Rotation(3, r);
            Rotation(4, -r);
        }
        else if (wheel[3][6] != wheel[2][2] && wheel[3][2] == wheel[4][6]) {//왼쪽만 가능
            if (wheel[1][2] == wheel[2][6]) {//막힘
                Rotation(3, r);
                Rotation(2, -r);
            }
            else if (wheel[1][2] != wheel[2][6]) {//회전
                Rotation(3, r);
                Rotation(2, -r);
                Rotation(1, r);
            }
        }
        else if (wheel[3][6] != wheel[2][2] && wheel[3][2] != wheel[4][6]) {//양쪽
            if (wheel[1][2] == wheel[2][6]) {//막힘
                Rotation(2, -r);
                Rotation(3, r);
                Rotation(4, -r);
            }
            else if (wheel[1][2] != wheel[2][6]) {//회전
                Rotation(1, r);
                Rotation(2, -r);
                Rotation(3, r);
                Rotation(4, -r);
            }
        }
        break;
    case 4:
        if (wheel[4][6] != wheel[3][2]) {
            if (wheel[3][6] != wheel[2][2]) {
                if (wheel[2][6] != wheel[1][2]) {
                    Rotation(4, r);
                    Rotation(3, -r);
                    Rotation(2, r);
                    Rotation(1, -r);
                }
                else {
                    Rotation(4, r);
                    Rotation(3, -r);
                    Rotation(2, r);
                }
            }
            else {
                Rotation(4, r);
                Rotation(3, -r);
            }
        }
        else Rotation(4, r);
        break;
    }

}
//점수
int Score() {
    int score1 = wheel[1][0] - '0';
    int score2 = 2*(wheel[2][0] - '0');
    int score3 = 4 * (wheel[3][0] - '0');
    int score4 = 8 * (wheel[4][0] - '0');
    return score1+score2+score3+score4;
}
//입력
void input() {
    for (int i = 1; i < maxi; i++) cin >> wheel[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> r;
        Pole(n,r);//극
    }
    cout<<Score();//점수
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    return 0;
}
