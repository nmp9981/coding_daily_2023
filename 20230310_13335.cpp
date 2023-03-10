#include <iostream>
#include <queue>
using namespace std;

int n,w,l;
const int maxi = 1001;
int truck[maxi];//트럭

//min
inline int min(int a,int b) {
	return a > b ? b : a;
}

//입력
void input() {
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) cin >> truck[i];
}
//트럭 이동
void Move() {
	queue<int> q;
	int weight = 0;
	int moveCnt = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			//꽉차면 뺀다.
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}
			//중량 초과
			if (weight + truck[i] > l) {
				q.push(0);
				moveCnt++;
			}
			else break;
		}
		//새로운 트럭 등록
		q.push(truck[i]);
		weight += truck[i];
		moveCnt++;
	}
	cout << moveCnt+w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Move();//트럭 이동
	return 0;
}
