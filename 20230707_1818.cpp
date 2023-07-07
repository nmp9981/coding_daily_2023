#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 200001;
int bookArray[maxi];//책 배열

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> bookArray[i];
}
//책 옮기기
void ShiftBook() {
    vector<int> arrange;//정리된 책
    for (int i = 0; i < n; i++) {
        int book = bookArray[i];
        if (arrange.size() == 0 || arrange[arrange.size() - 1] < book) arrange.push_back(book);
        else {
            int pos = lower_bound(arrange.begin(), arrange.end(), book) - arrange.begin();
            arrange[pos] = book;//새로운 위치에 책 넣기
        }
    }
    cout << n - arrange.size();//옮기는 책의 권수
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    ShiftBook();//책 옮기기
    return 0;
}
