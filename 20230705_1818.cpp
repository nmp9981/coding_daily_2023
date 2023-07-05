#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 200001;
int bookList[maxi];

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> bookList[i];
}
//책꽃이
void Bookshelf() {
    vector<int> book;
    for (int i = 0; i < n; i++) {
        if (book.size() == 0 || book[book.size() - 1] < bookList[i]) book.push_back(bookList[i]);
        else {
            int pos = lower_bound(book.begin(), book.end(), bookList[i]) - book.begin();
            book[pos] = bookList[i];
        }
    }
    cout << n-book.size();//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Bookshelf();//책꽃이
    return 0;
}
