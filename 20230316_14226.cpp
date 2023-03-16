#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 2001;
int imog[maxi][maxi];//i개 이모티콘을 만드는데 드는 최소 시간

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n;
}
//이모티콘
void Imoticon() {
	imog[1][0] = 1;//1개는 이미 입력
	queue<pair<int,int>> q;//현재 개수, 저장 개수, 시간
	q.push({ 1,0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int saved = q.front().second;
		q.pop();

		//완료
		if (cur == n) {
			cout << imog[cur][saved]-1;
			return;
		}
		//저장
		if (imog[cur][cur] == 0) {
			imog[cur][cur] = imog[cur][saved] + 1;
			q.push({ cur,cur });
		}
		//붙여넣기
		if ((cur + saved < maxi) && imog[cur + saved][saved] == 0) {
			imog[cur + saved][saved] = imog[cur][saved] + 1;
			q.push({ cur + saved,saved });
		}
		//삭제
		if (cur>0 && imog[cur - 1][saved] == 0) {
			imog[cur - 1][saved] = imog[cur][saved] + 1;
			q.push({ cur - 1,saved });
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	Imoticon();//이모티콘
	return 0;
}
