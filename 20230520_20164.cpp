#include <iostream>
#include <string>
using namespace std;

string num;
const int inf = 1000;
int minResult = inf;
int maxResult = 0;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> num;
}
//숫자 자르기
void CutNum(int cnt, string n) {
    if (n.size() == 1) {//1개
        int oddCount = 0;
        if (stoi(n) % 2 == 1) oddCount = 1;//홀수

        //결과
        minResult = min(minResult, cnt+oddCount);
        maxResult = max(maxResult, cnt+oddCount);
        return;
    }
    else if (n.size() == 2) {//2개
        //홀수 개수
        int oddCount = 0;
        for (int i = 0; i < n.size(); i++) {
            if ((n[i] - '0') % 2 == 1) oddCount++;
        }
        string sum = to_string((n[0] - '0') + (n[1] - '0'));
        CutNum(cnt + oddCount, sum);
    }else {//3개 이상
        //홀수 개수
        int oddCount = 0;
        for (int i = 0; i < n.size(); i++) {
            if ((n[i] - '0') % 2 == 1) oddCount++;
        }
        //3등분
        for (int i = 1; i < n.size() - 1; i++) {//2번째수 시작지점
            for (int j = i + 1; j < n.size(); j++) {//3번째수 시작지점
                int firstNum = stoi(n.substr(0, i));
                int secondNum = stoi(n.substr(i, j - i));
                int thirdNum = stoi(n.substr(j));

                string sum = to_string(firstNum+secondNum+thirdNum);//합
                CutNum(cnt+oddCount, sum);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CutNum(0,num);//숫자 자르기
    cout << minResult << " " << maxResult;//결과
    return 0;
}
