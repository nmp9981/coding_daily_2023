#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];//수열
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
}

//LIS
void LIS() {
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        if (lis.size() == 0 || lis[lis.size() - 1] < A[i]) lis.push_back(A[i]);
        else {
            int pos = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[pos] = A[i];
        }
    }
    cout << lis.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LIS();//LIS
    return 0;
}
