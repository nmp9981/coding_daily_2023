#include <iostream>
using namespace std;
typedef long long ll;

int n,ans;
ll dice[6];
ll vertex3[8][3] = { {0,1,2},{0,1,3},{0,2,4},{0,3,4},
    {5,1,2},{5,1,3},{5,2,4},{5,3,4} };
ll vertex2[12][2] = { {0,1},{0,2},{0,3},{0,4},
    {5,1},{5,2},{5,3},{5,4},
    {3,1},{3,4},{2,1},{2,4} };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < 6; i++) cin>>dice[i];
}
//꼭짓점
ll Vertex() {
    ll select3 = dice[vertex3[0][0]]+dice[vertex3[0][1]]+dice[vertex3[0][2]];
    for (int i = 0; i < 8; i++) select3 = min(select3, dice[vertex3[i][0]] + dice[vertex3[i][1]] + dice[vertex3[i][2]]);
    return 4*select3;//꼭짓점은 4개
}
//모서리
ll Edge(ll n) {
    ll select2 = dice[vertex2[0][0]]+dice[vertex2[0][1]];
    for (int i = 0; i < 12; i++) select2 = min(select2, dice[vertex2[i][0]] + dice[vertex2[i][1]]);
    return (4 * (n - 2) + 4 * (n - 1))*select2;
}
//면
ll Side(ll n) {
    ll select1 = dice[0];
    for (int i = 0; i < 6; i++) select1 = min(select1, dice[i]);
    return (4 * (n - 2) * (n - 1) + (n - 2) * (n - 2))*select1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    if (n == 1) {
        int sum = 0;
        ans = dice[0];
        for (int i = 0; i < 6; i++) {
            sum += dice[i];
            ans = max(ans, dice[i]);
        }
        cout << sum - ans;
    }else cout << Vertex()+Edge(n) +Side(n);//주사위 합
    return 0;
}
