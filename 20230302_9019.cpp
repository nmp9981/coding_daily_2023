#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class DSLR {
private:
	static const int maxi = 10001;
	const int mod = 10000;
	int start, end;
public:
	DSLR() {}//생성자 
	void input();//입력
	void Cal();//계산
};

//입력
void DSLR::input() {
	cin >> start >> end;
}
//계산
void DSLR::Cal() {
	bool visit[maxi];//방문 여부
	memset(visit, false, sizeof(visit));//초기화
	queue<pair<int,string>> q;
	q.push({ start,""});

	while (!q.empty()) {
		int num = q.front().first;
		string cmd = q.front().second;
		q.pop();

		//도착
		if (num==end ){
			cout << cmd << "\n";
			return;
		}

		//D
		int nextD = (2 * num)%mod;
		if (!visit[nextD]) {
			visit[nextD] = true;
			q.push({ nextD,cmd + "D" });
		}
		//S
		int nextS =(num-1+mod) % mod;
		if (!visit[nextS]) {
			visit[nextS] = true;
			q.push({ nextS,cmd + "S" });
		}
		//L
		int nextL = (num % 1000) * 10 + (num / 1000);
		if (!visit[nextL]) {
			visit[nextL] = true;
			q.push({ nextL, cmd + "L" });
		}
		//R
		int nextR = 1000 * (num % 10) + (num / 10);
		if (!visit[nextR]) {
			visit[nextR] = true;
			q.push({ nextR,cmd + "R" });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	DSLR dslr;
	for (int i = 0; i < t; i++) {
		dslr.input();
		dslr.Cal();
	}
	return 0;
}
