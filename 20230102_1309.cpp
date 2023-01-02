#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
const int mod = 9901;
int lion[maxi][3];//사자 배치 경우의 수

//동물원 배치
void Zoo() {
    lion[1][0] = 1; lion[1][1] = 1; lion[1][2] = 1;//왼, 오른쪽, 미설치
    for (int i = 2; i <= n; i++) {
        lion[i][0] = (lion[i - 1][1] + lion[i - 1][2])%mod;
        lion[i][1] = (lion[i - 1][0] + lion[i - 1][2])%mod;
        lion[i][2] = (lion[i - 1][0] + lion[i - 1][1] + lion[i - 1][2])%mod;
    }
    cout << (lion[n][0]+lion[n][1]+lion[n][2])%mod;//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    Zoo();//동물원 배치하기
    return 0;
}
