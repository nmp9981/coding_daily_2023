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
	sort(A, A + n);//오름차순 정렬
}
//좋은 수
void GoodNum() {
	int goodCnt = 0;//좋은 수의 개수
	for (int i = 0; i < n; i++) {
		//투포인터
		int left = 0;
		int right = n - 1;
		while (left < right) {
			if (A[left] + A[right] == A[i]) {//같다
				if (i != left && i != right) {
					goodCnt++;
					break;
				}
				if (i == left) left++;
				if (i == right) right--;
			}
			else if (A[left] + A[right] > A[i]) right--;//줄여야함
			else if (A[left] + A[right] < A[i]) left++;//늘려야함
		}
	}
	cout << goodCnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	GoodNum();//좋은 수
	return 0;
}
