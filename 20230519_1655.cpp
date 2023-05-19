#include <iostream>
#include <queue>
using namespace std;

int n,x;
priority_queue<int> maxQ;//최대 힙
priority_queue<int, vector<int>, greater<int>> minQ;//최소 힙

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//중앙값
void Median() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;//입력
        //번갈아가면서 원소 넣기
        if (i % 2 == 0) maxQ.push(x);
        else minQ.push(x);

        //교환
        if (minQ.size() >= 1 && maxQ.size() >= 1) {//각 힙에 원소가 있으면
            if (maxQ.top() > minQ.top()) {//최대힙이 더 크다
                int temp = maxQ.top();
                maxQ.pop();
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(temp);
            }
        }
        cout << maxQ.top()<<"\n";//출력
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Median();//중앙값
    return 0;
}
