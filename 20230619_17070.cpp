#include <iostream>
using namespace std;

int n;
const int maxi = 17;
int world[maxi][maxi];//지도
int caseNum[3][maxi][maxi];//경우의 수(0:가로, 1:세로,2:대각선)

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
}
//파이프 옮기기
void PipeMove() {
    //맨 윗줄
    for (int j = 1; j < n; j++) {
        if (world[0][j] == 1) break;
        caseNum[0][0][j] = 1;//가로만
    }
    //경우의 수
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (world[i][j] != 1) {
                if (world[i][j-1] != 1) caseNum[0][i][j] = caseNum[0][i][j - 1]+caseNum[2][i][j-1];//가로
                if (world[i-1][j] != 1) caseNum[1][i][j] = caseNum[1][i-1][j]+caseNum[2][i-1][j];//세로
                if (world[i - 1][j - 1]!=1 && world[i-1][j]!=1 && world[i][j-1]!=1) {//대각선
                    caseNum[2][i][j] = caseNum[0][i - 1][j - 1] + caseNum[1][i - 1][j - 1] + caseNum[2][i - 1][j - 1];
                }
            }
        }
    }
    cout << caseNum[0][n - 1][n - 1] + caseNum[1][n - 1][n - 1] + caseNum[2][n - 1][n - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    PipeMove();//파이프 옮기기
    return 0;
}
