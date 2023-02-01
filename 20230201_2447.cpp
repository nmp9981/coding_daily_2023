#include <iostream>
using namespace std;

int n;
//별찍기
void Star(int k,int x,int y) {
    if ((x / (k / 3))%3 == 1 && (y / (k / 3))%3 == 1) cout << " ";//공백
    else if (k == 3) cout << "*";//별
    else Star(k / 3, x, y);//재귀
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;//입력
    //별찍기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) Star(n, i, j);
        cout << "\n";
    }
    return 0;
}
