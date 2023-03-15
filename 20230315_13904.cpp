#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,d,w;
vector<pair<int, int>> homework;

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		homework.push_back({ d,w });
	}
	sort(homework.begin(), homework.end());//날짜 기준으로 정렬
}

//과제 수행
void Task() {
	priority_queue<int,vector<int>,greater<int>> pq;//최소힙
	for (int i = 0; i < n; i++) {
		int day = homework[i].first;
		int score = homework[i].second;

		pq.push(score);
		//기한 초과
		if (day < pq.size()) pq.pop();
	}
	//합 구하기
	int total = 0;
	while (!pq.empty()) {
		total += pq.top();
		pq.pop();
	}
	cout << total;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Task();//과제 수행
	return 0;
}
