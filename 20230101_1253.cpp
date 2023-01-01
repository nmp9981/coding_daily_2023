#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 2001;
vector<int> A;//수열

//모두 0인가?
bool allZero() {
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) return false;
    }
    return true;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());//정렬
}
//합
void Sum() {
    //모두 0
    if (allZero() == true && n>=3) {
        cout << n;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {//기준(A[idx]+A[j] = A[i])
        for (int j = 0; j < n; j++) {
            if (i == j) continue;//같은 위치
            auto idx = lower_bound(A.begin(),A.end(),A[i]-A[j]) - A.begin();//위치
            if (idx==i || idx==j) continue;//같은 위치
            if (A[idx] + A[j] == A[i]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Sum();//합
    return 0;
}
