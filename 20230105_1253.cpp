#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> A;//수열 A

//모두 0인가?
bool AllZero() {
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) return false;
    }
    return true;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());//정렬
}
//좋은 수
void GoodNum() {
    //모두 0일 때
    if (AllZero() && n >= 3) {
        cout << n;
        return;
    }
    int cnt=0;//개수
    for (int i = 0; i < n;i++) {//기준
        for (int j = 0;j<n;j++) {//A[j]+A[idx]=A[i]
            if (i == j) continue;//두 인덱스가 같다
            auto idx = lower_bound(A.begin(), A.end(), A[i] - A[j]) - A.begin();//위치
            if (idx == i || idx == j) continue;//인덱스가 같다.
            if (A[j] + A[idx] == A[i]) {
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
    GoodNum();//좋은 수
    return 0;
}
