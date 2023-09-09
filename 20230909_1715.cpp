#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> pq;//최소힙

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
}
//카드 정렬
void CardSort() {
    int total = 0;
    while (pq.size()>1) {
        int firstNum = pq.top();
        pq.pop();
        int secondNum = pq.top();
        pq.pop();

        int newNum = firstNum + secondNum;
        total += newNum;
        pq.push(newNum);
    }
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CardSort();//카드 정렬
    return 0;
}
