#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n,k;
int maxK[9];//각 자리 최대 k

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//min
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>k;
    maxK[1] = 9;
    for (int i = 2; i <= 8; i++) maxK[i] = maxK[i-1]+(i * 9 * pow(10, i - 1));
}
//k번째 숫자
void Kth() {
    //n은 몇까지 가능한가?
    int rek = 0;
    int i = 8;
    while (true) {
        if (n < pow(10, i)) i--;
        else {
            rek = maxK[i] + (i+1)*(n - pow(10, i)+1);
            break;
        }
    }
    if (k > rek) {//정답 없음
        cout << -1;
        return;
    }
    //한자리수
    if (k <= 9) cout << k;
    else {
        int idx = 8;
        while (true) {
            if (k <= maxK[idx]) idx--;
            else {
                k -= maxK[idx];
                k -= 1;//나머지 보정
                int rest = k % (idx + 1);
                int q = k / (idx + 1);
                int num = pow(10, idx) + q;
                string stringNum = to_string(num);
                cout << stringNum[rest];//출력
                break;
            }
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Kth();//k번째 숫자
    return 0;
}
