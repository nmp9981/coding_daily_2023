#include <iostream>
using namespace std;

int m,n,k;
const int maxi = 1001;
string world[maxi];//지도
int AreaCount[3][maxi][maxi];//각 영역별 개수

//입력
void input() {
    cin >> m>>n>>k;
    for (int i = 1; i <= m; i++) {
        cin >> world[i];
        world[i] = " " + world[i];
    }
}
//영역의 수 구하기
void Area() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            //정글
            if (world[i][j] == 'J') AreaCount[0][i][j] = AreaCount[0][i][j - 1] + AreaCount[0][i - 1][j] - AreaCount[0][i - 1][j - 1] + 1;
            else AreaCount[0][i][j] = AreaCount[0][i][j - 1] + AreaCount[0][i - 1][j] - AreaCount[0][i - 1][j-1];
            //바다
            if (world[i][j] == 'O') AreaCount[1][i][j] = AreaCount[1][i][j - 1] + AreaCount[1][i - 1][j] - AreaCount[1][i - 1][j - 1] + 1;
            else AreaCount[1][i][j] = AreaCount[1][i][j - 1] + AreaCount[1][i - 1][j] - AreaCount[1][i - 1][j - 1];
            //얼음
            if (world[i][j] == 'I') AreaCount[2][i][j] = AreaCount[2][i][j - 1] + AreaCount[2][i - 1][j] - AreaCount[2][i - 1][j - 1] + 1;
            else AreaCount[2][i][j] = AreaCount[2][i][j - 1] + AreaCount[2][i - 1][j] - AreaCount[2][i - 1][j - 1];
        }
    }
}

//질문
void Question() {
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //정글, 바다 ,얼음
        cout << AreaCount[0][c][d] - AreaCount[0][c][b - 1] - AreaCount[0][a - 1][d] + AreaCount[0][a - 1][b - 1]<<" ";
        cout << AreaCount[1][c][d] - AreaCount[1][c][b - 1] - AreaCount[1][a - 1][d] + AreaCount[1][a - 1][b - 1] << " ";
        cout << AreaCount[2][c][d] - AreaCount[2][c][b - 1] - AreaCount[2][a - 1][d] + AreaCount[2][a - 1][b - 1] << " ";
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Area();//영역 수 구하기
    Question();//질문
    return 0;
}
