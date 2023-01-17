#include <iostream>
using namespace std;

//별 찍기
void Star(int i,int j,int x) {//위치, 크기
    if ((i / (x / 3)) % 3 == 1 && (j / (x / 3)) % 3 == 1) cout << " ";//공백
    else if (x == 3) cout << "*";//별, 가장 작은 단위
    else Star(i, j, x / 3);//분할
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin >> n;
    //한줄씩 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) Star(i, j, n);
        cout << "\n";
    }
    return 0;
}
