#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll n,s;
const int maxi = 100001;
ll A[maxi];//수열

//입력
void input() {
    cin >> n>>s;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//부분합
void SubSum() {
    int left = 0;
    int right = 0;
    int sum = A[0];
    int minLen = maxi;

    while (left <= right && right<n) {
        if (sum >= s) {//합을 줄임
            if (right - left + 1 < minLen) minLen = right - left + 1;
            sum -= A[left];
            left++;
        }
        else {//합을 늘림
            right++;
            sum += A[right];
        }
    }
    if (minLen >= maxi) cout << 0;
    else cout << minLen;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SubSum();//부분합
    return 0;
}
