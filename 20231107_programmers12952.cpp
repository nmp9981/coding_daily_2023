#include <string>
#include <vector>
#include <cmath>
using namespace std;

int ans;
const int maxi = 13;
int selected[maxi];//각 행에 몇번열에 퀸이 있는가

//퀸을 놓을 수 있는가?
bool isNextQueen(int row) {//현재 놓는 위치(열, 행)
	for (int i = 0; i < row; i++) {//각 행 검사
		if (abs(selected[row]-selected[i]) == row-i || selected[row]==selected[i]) return false;//대각선, 같은줄
	}
	return true;
}
//n퀸 문제
void queen(int cnt,int n) {
	//완료
	if (cnt == n) {
		ans++;//경우의 수 증가
		return;
	}
	//몇번줄에 놓을건가?
	for (int i = 0; i < n; i++) {
		selected[cnt] = i;//cnt행 i번열에 퀸이 있다.
		if (isNextQueen(cnt)) {//놓을 수 있다면
			queen(cnt + 1,n);
		}
	}
}
int solution(int n) {
    queen(0,n);//경우의 수 세기
    return ans;
}
