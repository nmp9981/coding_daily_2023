#include <iostream>
#include <cmath>
using namespace std;

double Ascore,Bscore;//각 팀이 득점할 확률
const int maxi = 19;
int notPrime[12] = { 0,1,4,6,8,9,10,12,14,15,16,18 };//18이하 소수가 아닌 수
int nCr[maxi][maxi];//nCr

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//18Cn
void Comb18() {
    nCr[1][0] = 1; nCr[1][1] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];//조합
        }
    }
}
//득점 확률
void GetScore() {
    Ascore /= 100; Bscore /= 100;
    double Ateam = 0; double Bteam = 0;
    for (int i = 0; i < 12; i++) {//각 팀 소수가 아닌 점수로 득점할 확률
        int goal = notPrime[i];//골 횟수
        Ateam += (double)nCr[18][goal] * pow(Ascore, goal) * pow(1-Ascore, 18 - goal);
        Bteam += (double)nCr[18][goal] * pow(Bscore, goal) * pow(1-Bscore, 18 - goal);
    }
    double ans = 1 - Ateam * Bteam;//적어도 한팀이 소수로 득점
    printf("%.6f",ans);//출력
}
int main() {
    //빠른 입력
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> Ascore >> Bscore;//각 팀의 득점 확률
    Comb18();//18경기 중에서 이기는 경우의 수
    GetScore();//득점 확률
    return 0;
}
