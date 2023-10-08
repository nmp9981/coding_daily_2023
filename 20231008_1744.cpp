#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> positive;
vector<int> negative;
int one = 0;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 0) negative.push_back(x);
        else if (x == 1) one++;
        else if (x > 0) positive.push_back(x);
    }
    if(negative.size()>0) sort(negative.begin(), negative.end());
    if(positive.size()>0) sort(positive.begin(), positive.end());
}

//수묶기
void Tie() {
    //양수
    int plus = 0;
    if (positive.size() >= 2) {
        for (int i = positive.size() - 1; i >= 1; i -= 2) {
            plus += (positive[i] * positive[i - 1]);
        }
    }
    
    if (positive.size() % 2 == 1) plus += positive[0];
    //음수
    int minus = 0;
    if (negative.size() >= 2) {
        for (int i = 0; i < negative.size() - 1; i += 2) {
            minus += (negative[i] * negative[i + 1]);
        }
    }
    
    if (negative.size() % 2 == 1) minus += negative[negative.size() - 1];

    cout << plus + minus + one;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Tie();//수묶기
    return 0;
}
