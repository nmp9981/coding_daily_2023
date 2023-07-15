#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 200001;
int book[maxi];

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> book[i];
}
//책 옮기기
void BookMove() {
    vector<int> bookCase;//책꽃이
    for (int i = 0; i < n; i++) {
        if (bookCase.size() == 0 || book[i] > bookCase[bookCase.size() - 1]) {
            bookCase.push_back(book[i]);
        }
        int pos = lower_bound(bookCase.begin(), bookCase.end(), book[i])-bookCase.begin();
        bookCase[pos] = book[i];
    }
    cout << n - bookCase.size();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    BookMove();//책 옮기기
    return 0;
}
