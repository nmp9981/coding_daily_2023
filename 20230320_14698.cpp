#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int n;
const ll mod = 1000000007;
priority_queue<ll, vector<ll>, greater<ll>> pq;//최소 힙

//초기화
void init() {
	while (!pq.empty()) {
		pq.pop();
	}
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll energy;
		cin >> energy;
		pq.push(energy);
	}
}
//슬라임
void Slime() {
	ll cost = 1;//비용
	while (1) {
		//1개 남음
		if (pq.size() == 1) {
			cout << cost<<"\n";
			break;
		}

		//작은 두 수
		ll firstNum = pq.top();
		pq.pop();
		ll secondNum = pq.top();
		pq.pop();

		//새로운 슬라임
		ll newNum = firstNum * secondNum;
		pq.push(newNum);
		newNum %= mod;
		cost *= newNum;
		cost %= mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		init();//초기화
		input();//입력
		Slime();//슬라임
	}
	return 0;
}
