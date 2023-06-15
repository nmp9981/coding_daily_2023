#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k;
const int maxi = 31;
int pow2[maxi];
int csum[maxi];

//초기화
void init() {
    for (int i = 0; i < maxi; i++) pow2[i] = 1 << i;
    csum[1] = 2;
    for (int i = 2; i < maxi; i++) csum[i] = csum[i - 1] + pow2[i];
}
//입력
void input() {
    cin >> k;
}
//k번째 수 구하기
void kth() {
    //자릿수구하기
    int digit = 1;
    while (true) {
        if (csum[digit-1]<k && k<=csum[digit]) break;
        digit++;
    }
    //k번째 수 구하기
    string ans = "";
    k -= csum[--digit];
    while (digit>=0) {
        if (k > pow2[digit]) {
            ans += "7";
            k -= pow2[digit];
        }
        else ans += "4";
        digit--;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    kth();//k번째 수 구하기
    return 0;
}
