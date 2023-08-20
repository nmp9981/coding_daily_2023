#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 200001;
int A[maxi];//수열

//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

//LIS 구하기
void Lis() {
    vector<int> Lcs;
    for (int i = 0; i < n; i++) {
        if (Lcs.size() == 0 || Lcs[Lcs.size() - 1] < A[i]) Lcs.push_back(A[i]);
        else {
            int pos = lower_bound(Lcs.begin(), Lcs.end(), A[i]) - Lcs.begin();
            Lcs[pos] = A[i];
        }
    }
    cout <<n- Lcs.size();//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Lis();//LIS 구하기
    return 0;
}
