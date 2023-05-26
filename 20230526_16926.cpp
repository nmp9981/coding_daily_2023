#include <iostream>
#include <deque>
using namespace std;

struct Pos {
    int x, y, life;
};
int n, m, R;
const int maxi = 301;
int A[maxi][maxi];//배열

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m>>R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> A[i][j];
    }
}
//회전
void Rotation() {
    int newA[maxi][maxi];//새로운 배열
    int RotateCount = min(n, m) / 2;//돌리는 모서리 개수
    for (int k = 0; k < RotateCount; k++) {
        int startX = k; int startY = k; 
        int endX = n - 1 - k; int endY = m - 1 - k;
        //왼쪽
        for (int j = startY + 1; j <= endY; j++) newA[startX][j-1] = A[startX][j];
        //오른쪽
        for (int j = startY; j <= endY-1; j++) newA[endX][j + 1] = A[endX][j];
        //위쪽
        for (int i = startX + 1; i <= endX; i++) newA[i-1][endY] = A[i][endY];
        //아래쪽
        for (int i = startX; i <= endX-1; i++) newA[i + 1][startY] = A[i][startY];
    }
    //갱신
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) A[i][j] = newA[i][j];
    }
}
//출력
void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << A[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    for(int i=0;i<R;i++) Rotation();//이동
    output();//출력
    return 0;
}
