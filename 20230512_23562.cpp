#include <iostream>
using namespace std;

int n,m,a,b;
const int maxi = 21;
string board[maxi];//모눈종이
int total = 100000000;//총 비용

//입력
void input() {
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 0; i < n; i++) cin >> board[i];
}
//ㄷ 만들기
int MakeDigeut(int st_r,int st_c,int dSize) {
    int cost = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (r >= st_r && r < st_r + dSize && c >= st_c && c < st_c + 3 * dSize) {
                if (board[r][c] == '.') cost += a;//흰->검
            }else if (r >= st_r+dSize && r < st_r + 2*dSize && c >= st_c && c < st_c + dSize) {
                if (board[r][c] == '.') cost += a;//흰->검
            }else if (r >= st_r+2*dSize && r < st_r + 3*dSize && c >= st_c && c < st_c + 3 * dSize) {
                if (board[r][c] == '.') cost += a;//흰->검
            }else {
                if (board[r][c] == '#') cost += b;//검->흰
            }
        }
    }
    return cost;
}
//ㄷ 시작지점
void StartPoint() {
    for (int k = 1; k <= 6; k++) {//사이즈
        for (int i = 0; i <= n - 3 * k; i++) {//시작 지점
            for (int j = 0; j <= m - 3 * k; j++) {
                total = min(total, MakeDigeut(i,j,k));
            }
        }
    }
    cout << total;//비용
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    StartPoint();//ㄷ 시작 지점
    return 0;
}
