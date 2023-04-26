#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 2001;
vector<int> A;//수열

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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (A[left] + A[right] > A[i]) right--;//크면 줄인다.
            else if (A[left] + A[right] < A[i]) left++;//작으면 늘린다.
            else if (A[left] + A[right] == A[i]) {
                if (i == left) left++;//왼쪽수와 일치
                else if (i == right) right--;//오른쪽 수와 일치
                else {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    GoodNum();//좋은 수
    return 0;
}
