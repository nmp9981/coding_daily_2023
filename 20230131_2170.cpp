#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    int left, right;
};
int n;
vector<Line> board;

//정렬기준
bool cmp(Line A, Line B) {
    return A.left < B.left;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        board.push_back({ a,b });
    }
    sort(board.begin(), board.end(),cmp);//시작점 순으로 정렬
}
//그리기
int Draw() {
    int start = board[0].left; int End = board[0].right;
    int total = 0;//총 길이
    int sublength = End-start;//부분 길이
    for (int i = 1; i < n; i++) {
        int x = board[i].left;
        int y = board[i].right;

        //합치기
        if (x <= End && End<y) {//겹침, 길이 변화 있음
            End = y; 
            sublength = y - start;
        }
        else if(End < x) {//안겹침
            total += sublength;
            start = x; End = y;
            sublength = End - start;;
        }
    }
    total += sublength;//마지막 막대
    return total;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    cout<<Draw();//그리기
    return 0;
}
