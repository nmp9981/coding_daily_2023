#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> A;//수열

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());//오름차순 정렬
}
//수 선택
void SelectNum() {
    int left = 0;
    int right = 1;
    int minDiff = A[n-1] - A[0];
    while (left <= right && right<n) {
        int diff = A[right] - A[left];
        if (diff >= m) {
            left++;
            minDiff = min(minDiff, diff);
        }
        else right++;
    }
    cout << minDiff;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    SelectNum();//수 고르기
    return 0;
}
