#include <iostream>
using namespace std;

int n;
const int maxi = 10001;
int grape[maxi];//각 포도주의 양
int drink[maxi];//마시는 포도주의 양

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> grape[i];
}
//마시기
int Drink(int x) {
	//기저사례
	if (x == 0) return drink[x] = grape[x];
	if (x == 1) return drink[x] = grape[x] + grape[x - 1];
	if (x == 2) return drink[x] = max(max(grape[x - 1], grape[x - 2]) +grape[x], Drink(x - 1));

	if (drink[x]>0) return drink[x];//이미 값이 있다면

	//점화식
	drink[x] = max(Drink(x - 2), Drink(x - 3) + grape[x - 1]) + grape[x];
	drink[x] = max(Drink(x - 1), drink[x]);//안마시는 경우
	return drink[x];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	cout << Drink(n);//마시기
	return 0;
}
