#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];//수열

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >>n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

//공통 부분 문자열
void LIS() {
    vector<int> Lis;
    for (int i = 0; i < n; i++) {
        if (Lis.size() == 0 || Lis[Lis.size() - 1] < A[i]) Lis.push_back(A[i]);
        else {
            int pos = lower_bound(Lis.begin(),Lis.end(), A[i])-Lis.begin();
            Lis[pos] = A[i];
        }
    }
    cout << Lis.size();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LIS();//공통 부분 문자열
    return 0;
}
