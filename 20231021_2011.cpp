#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
const int maxi = 7001;
const int mod = 1000000;
int dp[maxi];//최대 길이

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> s;
    s = " " + s;
}
//LCS
void LCS() {
    //처음 2개
    if (s[1] - '0' == 0) {
        cout << 0;
        return;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < s.size(); i++) {
        int alphaNum = stoi(s.substr(i-1,2));
        if (s[i] - '0' == 0) {
            //10,20
            if (alphaNum == 10 || alphaNum == 20) dp[i] = dp[i - 2];
            else {
                cout << 0;
                return;
            }
        }
        else {
            if (alphaNum <= 9) dp[i] = dp[i - 1];
            else if (alphaNum >= 11 && alphaNum <= 26) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            else dp[i] = dp[i - 1];
        }
    }
    cout << dp[s.size() - 1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LCS();//LCS
    return 0;
}
