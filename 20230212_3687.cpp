#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,n;
const int maxi = 101;
string bigCnt[maxi] = { "0","0","1","7" };
string smallCnt[maxi] = { "0","0","1","7","4","2","6","8","10","18","22","20" };//i개로 만들 수 있는 가장 작은 수

//입력
void input() {
    cin >> n;
}
//작은 수
void SmallNumber(int x) {
    for (int i = 12; i <= x; i++) {
        smallCnt[i] = smallCnt[i - 7] + '8';
        if (i == 17) smallCnt[i] = "200";
    }
    cout << smallCnt[x];
}
//큰 수
void BigNumber(int x) {
    for (int i = 4; i <= x; i++) {
        bigCnt[i] = bigCnt[i - 2] + '1';
    }
    cout <<" " << bigCnt[x] << "\n";
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        input();//입력
        SmallNumber(n);//작은 수
        BigNumber(n);//큰 수
    }
    return 0;
}
