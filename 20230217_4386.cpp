#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
const int maxi = 101;
double dist[maxi][maxi];//거리 배열
vector<pair<double, double>> starPos;//별 위치
vector < pair<double, pair<int, int>>> star;//별
int root[maxi];//각 노드의 루트 노드

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		root[i] = i;//루트 노드 초기화
		double x, y;
		cin >> x >> y;
		starPos.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double d2 = pow(starPos[i].first - starPos[j].first, 2) + pow(starPos[i].second - starPos[j].second, 2);
			double d = sqrt(d2);
			star.push_back({ d,{i,j} });
		}
	}
	sort(star.begin(), star.end());//거리순 정렬
}

//find
int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

//연결
void Connect() {
	int node = 0;
	double total = 0;
	for (int i = 0; i < star.size(); i++) {
		double cost = star[i].first;
		int x = star[i].second.first;
		int y = star[i].second.second;

		//각 노드의 루트노드
		int rx = find(x);
		int ry = find(y);
		//다르면 연결
		if (rx != ry) {
			root[ry] = rx;
			node++;
			total += cost;
		}
		//모두 연결
		if (node == n - 1) {
			printf("%.2f", total);
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Connect();//연결
	return 0;
}
