#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,s;
const int maxi = 100001;
int A[maxi];//수열

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n >> s;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//부분합
void SubSum() {
    int left = 0;
    int right = 0;
    int sum = A[0];
    int len = maxi;

    while (left <= right && right<n) {
        //줄여야함
        if (sum >= s) {
            if (len > right-left+1) len = right - left + 1;
            sum -= A[left];
            left++;
        }
        else {//늘려야함
            right++;
            sum += A[right];
        }
    }
    //출력
    if (len >= maxi) cout << 0;
    else cout << len;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SubSum();//부분합
    return 0;
}
