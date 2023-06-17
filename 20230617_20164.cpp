#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string num;
int minAns = 100;
int maxAns = 0;
vector<int> A;//수열

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> num;
}
//수 나누기
void DivideNum(string n,int cnt) {
    if (n.size() == 1) {
        int oddCnt = 0;
        if ((n[0] - '0') % 2 == 1) oddCnt = 1;//홀수
        minAns = min(minAns, cnt + oddCnt);
        maxAns = max(maxAns, cnt + oddCnt);
        return;
    }
    else if (n.size() == 2) {
        int oddCnt = 0;
        for (int i = 0; i < n.size(); i++) {
            if ((n[i] - '0') % 2 == 1) oddCnt++;
        }
        string newNum = to_string((n[0]-'0')+(n[1]-'0'));
        DivideNum(newNum, cnt + oddCnt);
    }
    else if (n.size() >= 3) {
        //홀수 개수 구하기
        int oddCnt = 0;
        for (int i = 0; i < n.size(); i++) {
            if ((n[i] - '0') % 2 == 1) oddCnt++;
        }
        //3등분 하기
        for (int i = 1; i < n.size() - 1; i++) {
            for (int j = i + 1; j < n.size(); j++) {
                int firstNum = stoi(n.substr(0,i));
                int secondNum = stoi(n.substr(i,j-i));
                int thirdNum = stoi(n.substr(j));

                string newNum = to_string(firstNum + secondNum + thirdNum);//새로운 숫자
                DivideNum(newNum, cnt + oddCnt);//다음 숫자
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    DivideNum(num,0);//수 나누기
    cout << minAns << " " << maxAns;
    return 0;
}
