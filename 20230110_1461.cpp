#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int posiMax, negaMax;//양,음 최댓값
vector<int> plusDist;//양의 거리
vector<int> minusDist;//음의 거리

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int x;cin >>x;
		if (x > 0) plusDist.push_back(x);
		else if (x < 0) minusDist.push_back(-x);
	}
	//정렬
	if (plusDist.size() > 0) {
		sort(plusDist.begin(), plusDist.end());
		posiMax = plusDist[plusDist.size() - 1];
	}
	if (minusDist.size() > 0) {
		sort(minusDist.begin(), minusDist.end());
		negaMax = minusDist[minusDist.size() - 1];
	}
}
//도서관
void Library() {
	int dist = 0;
	for (int i = plusDist.size() - 1; i >= 0; i -= m) {//+
		dist += (plusDist[i] * 2);
	}
	for (int i = minusDist.size() - 1; i >= 0; i -= m) {//-
		dist += (minusDist[i] * 2);
	}
	if (posiMax > negaMax) dist -= posiMax;
	else dist -= negaMax;
	cout << dist;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	Library();//도서관
	return 0;
}
