#include <iostream>
using namespace std;

int c,n;
const int maxi = 100001;
int cost[maxi];//i원으로 만드는 최대 고객 수
int req[21];//요구치
int reward[21];//보상

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> c>>n;
    for (int i = 1; i <= n; i++) cin >> req[i] >> reward[i];
}
//홍보
void Promote() {
    for (int i = 1; i <= n; i++) {//번호
        for (int j = 0; j < maxi; j++) {//j원
            if(j-req[i]>=0) cost[j] = max(cost[j], cost[j - req[i]] + reward[i]);
        }
    }
    //c명 얻는 최소 비용
    for (int j = 0; j <= maxi; j++) {
        if (cost[j] >= c) {
            cout << j;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Promote();//광고
    return 0;
}
