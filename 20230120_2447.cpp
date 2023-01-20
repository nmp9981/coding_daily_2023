#include <iostream>
using namespace std;

//별직기
void Star(int x, int i, int j) {//크기, 위치
    if ((i / (x / 3)) %3== 1 && (j / (x / 3)) %3== 1) cout << " ";//공백
    else if (x == 3) cout << "*";//별, 가장 작은 단위
    else Star(x / 3, i, j);//분할
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    //한줄씩 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) Star(n, i, j);
        cout << "\n";
    }
    return 0;
}
