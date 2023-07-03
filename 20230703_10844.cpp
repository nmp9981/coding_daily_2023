#include <iostream>
using namespace std;

int n;
const int maxi = 101;
const int mod = 1000000000;
int stair[maxi][10];//자릿수 i ,끝자리 j

//계단 수 구하기
void StairNum() {
    for (int j = 1; j < 10; j++) stair[1][j] = 1;

    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) stair[i][j] = stair[i - 1][1];
            else if (j == 9) stair[i][j] = stair[i - 1][8];
            else stair[i][j] = (stair[i - 1][j + 1] + stair[i - 1][j - 1])%mod;
        }
    }
}
//입력
void input() {
    cin >> n;
}
//출력
void output() {
    int total = 0;
    for (int j = 0; j < 10; j++) total = (total+stair[n][j])%mod;
    cout << total % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    StairNum();//계단 수
    input();//입력
    output();//출력
    return 0;
}
