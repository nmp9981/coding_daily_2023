#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 301;
vector<int> A;//배열

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    sort(A.begin(),A.end());//오름차순 정렬
}

//좋은 수
void GoodNum() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {//각 수에 대해
        int num = A[i];
        int left = 0;
        int right = n - 1;

        while (left < right) {
            if (A[left] + A[right] == num) {//좋은 수
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                cnt++;
                break;
            }
            else if (A[left] + A[right] < num) left++;//늘려야함
            else if (A[left] + A[right] > num) right--;//줄여야함
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
