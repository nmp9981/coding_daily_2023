#include <iostream>
using namespace std;

int n;
const int maxi = 31;
int tile[maxi];//타일 채우는 경우의 수

//타일 경우의 수 구하기
void Tile() {
    tile[1] = 1;
    tile[2] = 3;
    for (int i = 3; i < maxi; i++) tile[i] = tile[i - 1] + 2 * tile[i - 2];
}
//코드 개수 구하기
void Code() {
    if (n < 3) tile[n] = tile[n];
    else if (n % 2 == 0) {//짝수
        tile[n] = (tile[n] + tile[n / 2] + 2 * tile[(n-2)/2]) / 2;
    }
    else if(n%2==1) {//홀수
        tile[n] = (tile[n / 2] + tile[n]) / 2;
    }
    cout << tile[n];
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;//입력
    Tile();//타일 경우의 수
    Code();//코드 개수 구하기
    return 0;
}
