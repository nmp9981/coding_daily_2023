#include <iostream>
using namespace std;

int n;
const int maxi = 21;
int health[maxi];//체력
int pleasure[maxi];//기쁨
int getExp[maxi][101];//i번까지 인사했고 남은 체력 j일때 얻는 기쁨

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> health[i];
    for (int i = 1; i <= n; i++) cin >> pleasure[i];
}
//기쁨 얻기
void GetPleasure() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (j > health[i]) getExp[i][j] = max(getExp[i - 1][j], getExp[i-1][j - health[i]]+pleasure[i]);//체력 충분 
            else getExp[i][j] = getExp[i - 1][j];//체력 부족
        }
    }
    cout << getExp[n][100];//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    GetPleasure();//기쁨 얻기
    return 0;
}
