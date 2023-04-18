#include <iostream>
#include <vector>
#include <string>
using namespace std;

string num;
int minOdd = 100;
int maxOdd = 0;

//max
int inline max(int x, int y) {
    return x > y ? x : y;
}
//min
int inline min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> num;
}
//자르기
void Cut(int len,int cnt,string n) {
    //길이 1
    if (len == 1) {
        if ((n[0] - '0') % 2 == 1) cnt++;

        minOdd = min(minOdd, cnt);
        maxOdd = max(maxOdd, cnt);
        return;
    }
    else if (len == 2) {//길이 2
        //홀수 개수
        int oddCnt = 0;
        for (int i = 0; i < len; i++) {
            if ((n[i] - '0') % 2 == 1) oddCnt++;
        }
        string newNum = to_string((n[0] - '0') + (n[1] - '0'));//새로운 수
        Cut(newNum.size(), cnt + oddCnt, newNum);//다음 숫자(홀수 개수 누적)
    }
    else if (len >= 3) {//길이 3이상
        //홀수 개수
        int oddCnt = 0;
        for (int i = 0; i < len; i++) {
            if ((n[i] - '0') % 2 == 1) oddCnt++;
        }
        //3등분
        for (int i = 1; i < len - 1; i++) {//2번 숫자 시작 지점
            for (int j = i+1; j < len; j++) {//3번 숫자 시작 지점
                string firstNum = n.substr(0, i);
                string secondNum = n.substr(i, j - i);
                string thirdNum = n.substr(j, len - j);

                string newNum = to_string(stoi(firstNum) + stoi(secondNum) + stoi(thirdNum));//새로운 수
                Cut(newNum.size(), cnt+oddCnt, newNum);//다음 숫자(홀수 개수 누적)
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Cut(num.size(),0,num);//자르기
    cout << minOdd << " " << maxOdd;//출력
    return 0;
}
