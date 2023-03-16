#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 1001;
int A[maxi];//수열
int Len[maxi];//길이
vector<int> ans;//정답 수열

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//초기화
void init() {
	for (int i = 0; i < n; i++) Len[i] = 1;//기본적으로 길이 1
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	init();//초기화
}
//LIS
void LIS() {
	int maxIdx = 0; int maxLen = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[j] > A[i]) {
				Len[j] = max(Len[j], Len[i] + 1);
				maxIdx = j;
				maxLen = max(Len[j],maxLen);
			}
		}
	}
	cout << maxLen << "\n";

	int len = maxLen;
	for (int i = maxIdx; i >= 0; i--) {
		if (Len[i] == len) {
			ans.push_back(A[i]);
			len--;
		}
	}
}
//출력
void output() {
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	LIS();//LIS
	output();//출력
	return 0;
}
