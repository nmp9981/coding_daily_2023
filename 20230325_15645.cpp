#include <iostream>
#include <queue>
using namespace std;

int n;
const int maxi = 100001;
int board[maxi][3];//보드
int maxDP[maxi][3];//최댓값
int minDP[maxi][3];//최솟값

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) cin >> board[i][j];
    }
}
//최대 점수
void MaxScore() {
    for (int j = 0; j < 3; j++) maxDP[0][j] = board[0][j];

    for (int i = 1; i < n; i++) {
        maxDP[i][0] = board[i][0] + max(maxDP[i - 1][0], maxDP[i - 1][1]);
        maxDP[i][1] = board[i][1] + max(maxDP[i - 1][0], max(maxDP[i - 1][1],maxDP[i-1][2]));
        maxDP[i][2] = board[i][2] + max(maxDP[i - 1][1], maxDP[i - 1][2]);
    }
    cout << max(maxDP[n - 1][0], max(maxDP[n - 1][1], maxDP[n - 1][2]))<<" ";
}
//최소 점수
void MinScore() {
    for (int j = 0; j < 3; j++) minDP[0][j] = board[0][j];

    for (int i = 1; i < n; i++) {
        minDP[i][0] = board[i][0] + min(minDP[i - 1][0], minDP[i - 1][1]);
        minDP[i][1] = board[i][1] + min(minDP[i - 1][0], min(minDP[i - 1][1], minDP[i - 1][2]));
        minDP[i][2] = board[i][2] + min(minDP[i - 1][1], minDP[i - 1][2]);
    }
    cout << min(minDP[n - 1][0], min(minDP[n - 1][1], minDP[n - 1][2])) << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MaxScore();//최대 점수
    MinScore();//최소 점수
    return 0;
}
