#include <iostream>
using namespace std;

int n;

//입력
void input() {
    cin >> n;
}

//별찍기
void Star(int x, int y, int k) {
    if ((x / (k / 3))%3 == 1 && (y / (k / 3))%3 == 1) cout << " ";//공백
    else if (k == 3) cout << "*";//분할 완료
    else Star(x, y, k / 3);//분할
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) Star(i, j, n);//별찍기
        cout << "\n";
    }
    return 0;
}
