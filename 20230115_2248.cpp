#include <iostream>
using namespace std;
typedef unsigned int uint;

uint n,l,k;
const int maxi = 32;
uint nCr[maxi][maxi];//i자리에서 1을 j개 쓰는 경우의 수

//min
inline int min(uint x, uint y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n >> l>>k;
}
//조합
void comb() {
    nCr[1][0] = 1; nCr[1][1] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
        }
    }
}
//숫자 구하기
void search(uint x) {
    for (int i = n - 1; i >= 1; i--) {
        uint sum = 0;
        for (int j = 0; j <= min(i, l); j++) sum += nCr[i][j];
        if (sum < x) {//1
            cout << 1;
            x -= sum;
            l--;//1사용
        }
        else cout << 0;//0
    }
    if (x == 1) cout << 0;
    else if (x == 2) cout << 1;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    comb();//조합
    search(k);//숫자 구하기
    return 0;
}
