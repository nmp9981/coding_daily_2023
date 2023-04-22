#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
const int mod = 9901;
int zoo[maxi][3];//동물원

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n;
    zoo[1][0] = 1;
    zoo[1][1] = 1;
    zoo[1][2] = 1;
}
//동물원
void Zoo() {
    for (int i = 2; i <= n; i++) {
        zoo[i][0] = (zoo[i-1][1] + zoo[i-1][2])%mod;
        zoo[i][1] = (zoo[i-1][0] + zoo[i-1][2])%mod;
        zoo[i][2] = (zoo[i-1][0] + zoo[i-1][1] + zoo[i-1][2])%mod;
    }
    cout << (zoo[n][0] + zoo[n][1] + zoo[n][2])%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Zoo();//동물원
    return 0;
}
