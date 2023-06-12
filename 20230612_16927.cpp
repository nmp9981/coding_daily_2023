#include <iostream>
using namespace std;

int n,m,R;
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
//출력
void output() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout<< A[i][j]<<" ";
        cout << "\n";
    }
}
//회전
void Rotation() {
    int edgeCnt = min(n, m)/2;
    for (int k = 0; k < edgeCnt; k++) {
        int startR = k; int startC = k;
        int endR = n - 1 - k; int endC = m - 1 - k;

        int edgeLen = 2*(n+m-2-4*k);//모서리 길이
        int Rcount = R % edgeLen;//회전 횟수
        while(Rcount--) {
            int temp = A[startR][startC];
            for (int j = startC + 1; j <= endC; j++) A[startR][j - 1] = A[startR][j];//북
            for (int i = startR + 1; i <= endR; i++) A[i - 1][endC] = A[i][endC];//동
            for (int j = endC - 1; j >= startC; j--) A[endR][j + 1] = A[endR][j];//남
            for (int i = endR - 1; i >= startR; i--) A[i + 1][startC] = A[i][startC];//서
            A[startR + 1][startC] = temp;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Rotation();//회전
    output();//출력
    return 0;
}
