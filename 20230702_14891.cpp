#include <iostream>
#include <cmath>
using namespace std;

int k;
const int maxi = 1001;
string cogWheel[4];//톱니바퀴

//회전
void Rotation(int num, int dir) {
    if (dir == 1) {//시계
        string temp = cogWheel[num - 1].substr(0, 7);
        cogWheel[num - 1] = cogWheel[num-1][7]+temp;
    }
    else if (dir == -1) {//반시계
        string temp = cogWheel[num - 1].substr(1, 7);
        cogWheel[num - 1] = temp+cogWheel[num-1][0];
    }
}
//회전 여부
void Decide(int num, int dir) {
    switch (num) {
    case 1:
        if (cogWheel[0][2] != cogWheel[1][6]) {
            if (cogWheel[1][2] == cogWheel[2][6]) {//1,2만 회전
                Rotation(1, dir);
                Rotation(2, -dir);
            }
            else {
                if (cogWheel[2][2] == cogWheel[3][6]) {//1,2,3회전
                    Rotation(1, dir);
                    Rotation(2, -dir);
                    Rotation(3, dir);
                }
                else {//1,2,3,4회전
                    Rotation(1, dir);
                    Rotation(2, -dir);
                    Rotation(3, dir);
                    Rotation(4, -dir);
                }
            }
        }
        else Rotation(1, dir);//1 회전
        break;
    case 2:
        if (cogWheel[0][2] != cogWheel[1][6] && cogWheel[1][2] == cogWheel[2][6]) {//1,2회전
            Rotation(2, dir);
            Rotation(1, -dir);
        }
        else if (cogWheel[0][2] == cogWheel[1][6] && cogWheel[1][2] != cogWheel[2][6]) {
            if (cogWheel[2][2] == cogWheel[3][6]) {//2,3회전
                Rotation(2, dir);
                Rotation(3, -dir);
            }
            else {//2,3,4회전
                Rotation(2, dir);
                Rotation(3, -dir);
                Rotation(4, dir);
            }
        }
        else if(cogWheel[0][2] != cogWheel[1][6] && cogWheel[1][2] != cogWheel[2][6]){
            if (cogWheel[2][2] == cogWheel[3][6]) {//1,2,3회전
                Rotation(1, -dir);
                Rotation(2, dir);
                Rotation(3, -dir);
            }
            else {//1,2,3,4회전
                Rotation(1, -dir);
                Rotation(2, dir);
                Rotation(3, -dir);
                Rotation(4, dir);
            }
        }else Rotation(2, dir);//2 회전
        break;
    case 3:
        if (cogWheel[2][2] != cogWheel[3][6] && cogWheel[1][2] == cogWheel[2][6]) {//3,4회전
            Rotation(3, dir);
            Rotation(4, -dir);
        }
        else if (cogWheel[2][2] == cogWheel[3][6] && cogWheel[1][2] != cogWheel[2][6]) {
            if (cogWheel[0][2] == cogWheel[1][6]) {//2,3회전
                Rotation(2, -dir);
                Rotation(3, dir);
            }
            else {//1,2,3회전
                Rotation(1, dir);
                Rotation(2, -dir);
                Rotation(3, dir);
            }
        }
        else if(cogWheel[2][2] != cogWheel[3][6] && cogWheel[1][2] != cogWheel[2][6]){
            if (cogWheel[0][2] == cogWheel[1][6]) {//2,3,4회전
                Rotation(2, -dir);
                Rotation(3, dir);
                Rotation(4, -dir);
            }
            else {//1,2,3,4회전
                Rotation(1, dir);
                Rotation(2, -dir);
                Rotation(3, dir);
                Rotation(4, -dir);
            }
        }
        else Rotation(3, dir);//3 회전
        break;
    case 4:
        if (cogWheel[2][2] != cogWheel[3][6]) {
            if (cogWheel[1][2] == cogWheel[2][6]) {//3,4만 회전
                Rotation(3, -dir);
                Rotation(4, dir);
            }
            else {
                if (cogWheel[0][2] == cogWheel[1][6]) {//2,3,4회전
                    Rotation(2, dir);
                    Rotation(3, -dir);
                    Rotation(4, dir);
                }
                else {//1,2,3,4회전
                    Rotation(1, -dir);
                    Rotation(2, dir);
                    Rotation(3, -dir);
                    Rotation(4, dir);
                }
            }
        }
        else Rotation(4, dir);//4 회전
        break;
    }
}
//입력
void input() {
    for (int i = 0; i < 4; i++) cin >> cogWheel[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        Decide(num, dir);//회전 여부
    }
}
//점수
void Score() {
    int total = 0;
    for (int i = 0; i < 4; i++) total += ((cogWheel[i][0] - '0') * pow(2, i));
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Score();//점수
    return 0;
}
