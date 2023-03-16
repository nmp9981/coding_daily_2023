#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];//수열

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
}

//LIS
void LIS() {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (v.size() == 0 || A[i] > v.back()) v.push_back(A[i]);
		else {
			int pos = lower_bound(v.begin(), v.end(),A[i]) - v.begin();
			v[pos] = A[i];
		}
	}
	cout << v.size();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	LIS();//LIS
	return 0;
}
