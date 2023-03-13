#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
vector<pair<int,pair<int,int>>> Up;//오르막길 기준
vector<pair<int, pair<int, int>>> Down;//내리막길 기준
int root[maxi];//i번 노드의 루트노드
int upTired, downTired;

//초기화
void init() {
	for (int i = 0; i <= n; i++) root[i] = i;
}
//입력
void input() {
	cin >> n>>m;
	init();
	for (int i = 0; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Up.push_back({ c - 1, {a, b} });
		Down.push_back({ 1 - c,{a,b} });
	}
	//피로도 순 정렬
	sort(Up.begin(), Up.end());
	sort(Down.begin(), Down.end());
}

//루트 노드
int find(int k) {
	if (root[k] == k) return k;
	return root[k] = find(root[k]);
}
//오르막 기준
int UpMove() {
	int node = 0;
	int tired = 0;
	int up_size = Up.size();
	for (int i = 0; i < up_size; i++) {
		int cost = Up[i].first;
		int x = Up[i].second.first;
		int y = Up[i].second.second;

		int px = find(x);
		int py = find(y);
		//루트노드가 다르다면 연결
		if (px != py) {
			root[py] = px;
			node++;
			tired += cost;
		}
		//연결 완료
		if (node == n) break;
	}
	return tired * tired;
}
//오르막 기준
int DownMove() {
	int node = 0;
	int tired = 0;
	int down_size = Down.size();
	for (int i = 0; i < down_size; i++) {
		int cost = Down[i].first;
		int x = Down[i].second.first;
		int y = Down[i].second.second;

		int px = find(x);
		int py = find(y);
		//루트노드가 다르다면 연결
		if (px != py) {
			root[py] = px;
			node++;
			tired += cost;
		}
		//연결 완료
		if (node == n) break;
	}
	return tired * tired;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	upTired = UpMove();//오르막 기준
	init();//초기화
	downTired = DownMove();//내림차순 기준
	cout << abs(upTired - downTired);//출력
	return 0;
}
