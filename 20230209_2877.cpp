#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k;
const int maxi = 31;
int two[maxi];//2의 거듭제곱 합

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> k;
}
//2의 거듭지수
void Power2() {
    two[1] = 2;
    for (int i = 2; i < maxi; i++) two[i] = two[i-1]+ pow(2,i);
}
//k번째 수
void kth() {
    //자릿수 구하기
    int digit = 0;
    for (int i = 0; i <maxi; i++) {
        if (two[i] >= k) {
            digit = i;
            break;
        }
    }
    vector<int> ans;
    k -= two[digit - 1];
    for (int i = digit-1; i > 0; i--) {
        if (k > pow(2, i)) {
            ans.push_back(7);
            k -= pow(2, i);
        }
        else ans.push_back(4);
    }
    //마지막 자리
    if (k == 1) ans.push_back(4);
    else if (k == 2) ans.push_back(7);
    //출력
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Power2();//2의 거듭지수
    kth();//k번째 수
    return 0;
}
