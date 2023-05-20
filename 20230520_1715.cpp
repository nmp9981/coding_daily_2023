#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;//최소힙

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
}
//비교횟수
void CompareCount() {
    int cnt = 0;
    while (pq.size() > 1) {
        //앞 2개꺼내기
        int firstNum = pq.top();
        pq.pop();
        int secondNum = pq.top();
        pq.pop();

        //더하기
        int sum = firstNum + secondNum;
        cnt += sum;
        pq.push(sum);
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CompareCount();//비교횟수
    return 0;
}
