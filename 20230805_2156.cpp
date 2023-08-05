#include <iostream>
using namespace std;

int n;
const int maxi = 10001;
int grape[maxi];
int drink[maxi];
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin>>n;
    for (int i = 1; i <= n; i++) cin >> grape[i];
}

//마시기
void Drink() {
    drink[1] = grape[1];
    drink[2] = grape[1] + grape[2];
    drink[3] = max(drink[2], grape[3] + max(grape[1], grape[2]));

    for (int i = 4; i <= n; i++) {
        drink[i] = max(drink[i-1],max(grape[i] + drink[i - 2],grape[i]+grape[i-1]+drink[i-3] ));
    }
    cout << drink[n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Drink();//마시기
    return 0;
}
