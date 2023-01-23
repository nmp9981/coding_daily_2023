#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,s;
const int maxi = 100001;
int A[maxi];//수열

//입력
void input() {
    cin >> n>>s;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//합 구간 구하기
void SubSum() {
    int len = maxi;
    int left=0, right=0;
    int sum = A[0];
    while (left <= right && right < n) {
        if (sum >= s) {//합이 더 크므로 줄여야함
            if (len > right - left + 1) len = right - left + 1;//구간 길이 갱신
            sum -= A[left];
            left++;
        }
        else {//합이 더 작으므로 늘려야함
            right++;
            sum += A[right];
        }
    }
    //출력
    if (len >= maxi) cout << 0;
    else cout << len;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    SubSum();//합 구간 구하기
    return 0;
}
