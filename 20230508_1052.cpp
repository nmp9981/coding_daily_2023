#include <iostream>
using namespace std;

int n,k;
//입력
void input() {
    cin >> n >> k;
}
//물병 이동
void Move() {
    int cnt = 0;
    while (true) {
        int bitCnt = 0;
        int num = n + cnt;
        //비트 개수 구하기
        for (int i = 0; i < 25; i++) {
            if (num & (1 << i)) bitCnt++;
        }
        //비트 개수가 k이하
        if (bitCnt <= k) {
            cout << cnt;
            return;
        }
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Move();//물병 이동
    return 0;
}
