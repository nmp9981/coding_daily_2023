#include <iostream>
using namespace std;

int n;
const int maxi = 1001;
int A[maxi];//수열
int frontLIS[maxi];//정방향
int backLIS[maxi];//역방향
int bitonicLen = 0;//바이토닉 수열 길이

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		frontLIS[i] = 1;
		backLIS[i] = 1;
	}
}
//바이토닉 수열
void Bitonic() {
	//최장 증가수열로 구한다.(정방향)
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (A[i] < A[j]) frontLIS[j] = max(frontLIS[j], frontLIS[i] + 1);
		}
	}
	//역방향
	for (int i = n-1; i >= 0; i--) {
		for (int j = i -1; j >=0; j--) {
			if (A[i] < A[j]) backLIS[j] = max(backLIS[j], backLIS[i] + 1);
		}
	}
	//수열 길이 구하기
	for (int i = 0; i < n; i++) bitonicLen = max(bitonicLen, frontLIS[i] + backLIS[i]-1);
	cout << bitonicLen;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Bitonic();//바이토닉 수열
	return 0;
}
