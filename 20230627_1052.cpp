#include <iostream>
using namespace std;

int n,k;
const int maxi = 25;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//물병 이동
void Move() {
    int cnt = 0;
    while (true) {
        int bitCnt = 0;
        int num = n + cnt;
        //1의 개수 구하기
        for (int i = 0; i < maxi; i++) {
            if (num & (1 << i)) bitCnt++;
        }
        if (bitCnt <= k) break;//k이하
        cnt++;
    }
    cout << cnt;
}
//입력
void input() {
    cin >> n >> k;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move();//물병 이동
    return 0;
}
