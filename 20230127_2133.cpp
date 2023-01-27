#include <iostream>
using namespace std;

int n;
const int maxi = 31;
int tile[maxi];//타일 채우는 경우의 수

//타일 설치
void Tile() {
    tile[0] = 1;
    tile[2] = 3;
    for (int i = 4; i < maxi; i += 2) {
        tile[i] = 3*tile[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) tile[i] += 2 * tile[j];
    }
    cout << tile[n];//출력
}

int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;//입력
    if (n & 1) cout << 0;
    else Tile();//타일 설치
    return 0;
}
