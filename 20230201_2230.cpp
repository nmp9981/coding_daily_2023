#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
const int maxi = 100001;
vector<int> A;//수열

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());//정렬
}
//차이 구하기
void Diff() {
    int left = 0; int right = 1;
    int ans = A[n-1] - A[0];//가장 작은 차이
    while (left <= right && right < n) {
        int diff = A[right] - A[left];//차이
        if (diff >= m) {//차이가 m이상
            if (ans > diff) ans = diff;//더 작은 차이
            left++;
        }
        else right++;
    }
    cout << ans;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Diff();//차이 구하기
    return 0;
}
