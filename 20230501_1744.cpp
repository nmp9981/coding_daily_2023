#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int one = 0;
vector<int> Plus;
vector<int> Minus;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 1) Plus.push_back(x);
        else if (x == 1) one++;
        else Minus.push_back(-x);
    }
    //오름차순 정렬
    sort(Plus.begin(), Plus.end());
    sort(Minus.begin(), Minus.end());
}
//수 묶기
void Bind() {
    int total = 0;
    //+
    for (int i = Plus.size() - 1; i > 0; i-=2) {
        total += (Plus[i] * Plus[i - 1]);
    }
    if (Plus.size() % 2 == 1) total += Plus[0];

    //-
    for (int i = Minus.size() - 1; i > 0; i -= 2) {
        total += (Minus[i] * Minus[i - 1]);
    }
    if (Minus.size() % 2 == 1) total -= Minus[0];

    cout << total + one;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Bind();//수 묶기
    return 0;
}
