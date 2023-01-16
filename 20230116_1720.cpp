#include <iostream>
using namespace std;

int n;
const int maxi = 31;
int tile[maxi];//타일 경우의 수

//입력
void input() {
    cin >> n;
}
//경우의 수
void Case() {
    tile[1] = 1; tile[2] = 3;
    if (n < 3) return;
    //총 경우의 수
    for (int i = 3; i <= n; i++) tile[i] = 2*tile[i - 2] + tile[i - 1];
    //중복 고려
    if (n % 2 == 1) tile[n] = (tile[n / 2] + tile[n]) / 2;//홀수
    else if (n % 2 == 0) tile[n] = (tile[n]+tile[n/2]+2*tile[n/2-1])/2;//짝수
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Case();//경우의 수
    cout << tile[n];//출력
    return 0;
}
