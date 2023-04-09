#include <iostream>
using namespace std;
typedef long long ll;

int n;
const int maxi = 31;
ll drug[maxi][maxi];//정상, 반쪽

//경우의 수
ll CaseNum(int full, int half) {
    if (drug[full][half] > 0) return drug[full][half];//이미 있음
    if (full == 0) return drug[full][half] = 1;

    if (half == 0) drug[full][half] = CaseNum(full - 1, half + 1);
    else drug[full][half] = CaseNum(full - 1, half + 1) + CaseNum(full, half - 1);
    return drug[full][half];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    drug[1][0] = 1;
    CaseNum(maxi-1,1);//경우의 수 구하기
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << drug[n][0] << "\n";
    }
    return 0;
}
