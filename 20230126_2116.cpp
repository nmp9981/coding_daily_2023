#include <iostream>
#include <queue>
using namespace std;

int n;
int total = 0;
const int maxi = 10001;
int dice[maxi][6];//주사위

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//주사위 밑면
int diceBottom(int x) {
    if (x == 0 || x == 5) return 5 - x;
    else if (x == 1 || x == 3) return 4 - x;
    else if (x == 2 || x == 4) return 6 - x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) cin >> dice[i][j];
    }
}
//주사위
int Dice(int x) {
    int sum = 0;//총합
    int up = x;//윗면 번호
    for (int i = 0; i < n; i++) {
        int bottom = diceBottom(up);//밑면 번호
        int Side = 0;//옆면 최댓값
        for (int j = 0; j < 6; j++) {
            if (j == up || j == bottom) continue;
            if (Side < dice[i][j]) Side = dice[i][j];
        }
        //다음 윗면
        for (int j = 0; j < 6; j++) {
            if (dice[i][bottom]==dice[i+1][j]) up = j;
        }
        sum += Side;
    }
    return sum;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    for(int i=0;i<6;i++) total = max(total,Dice(i));//주사위 윗면
    cout << total;//출력
    return 0;
}
