#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int maxi = 2001;
int A[maxi];//수열

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);//오름 차순 정렬
}
//좋은 수
int GoodNum() {
    int cnt = 0;
    //각 수에 대해
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n-1;
        //투 포인터
        while (left < right) {
            int sum = A[left] + A[right];//합

            if (sum == A[i]) {
                //자기 자신을 포함하면 안됨
                if (left != i && right != i) {
                    cnt++;
                    break;
                }
                //자기 자신
                if (left == i) left++;
                if (right == i) right--;
            }
            else if (sum > A[i]) right--;//낮춰야함
            else if (sum < A[i]) left++;//높여야함
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<GoodNum();//좋은 수
    return 0;
}
