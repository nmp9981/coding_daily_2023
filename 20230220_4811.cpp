#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 31;
ll drug[maxi][maxi];

//알약
ll Pill(int x, int y) {
	if (drug[x][y] > 0) return drug[x][y];//이미 값이 있음

	if (x == 0) return drug[x][y] = 1;

	//점화식
	if (y == 0) drug[x][y] = Pill(x - 1, y + 1);
	else drug[x][y] = Pill(x - 1, y + 1) + Pill(x, y - 1);
	return drug[x][y];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Pill(30, 0);//알약
	while (true) {
		cin >> n;
		if (n == 0) break;
		cout << drug[n][0] << "\n";
	}
	return 0;
}
