#include <string>
#include <vector>
using namespace std;

const int maxi = 100001;
const int mod = 1000000007;
int dp[101][maxi];//i번째 동전 j원을 거슬러주는 경우의 수

//초기화
void init(int n, vector<int> money){
    for(int i=0;i<=n;i++){
        if(i%money[0]==0) dp[0][i] = 1;
    }
}
//거스름 돈
int Change(int n,vector<int> money){
    for(int i=1;i<money.size();i++){
        for(int j=0;j<=n;j++){
            if(j<money[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j]+dp[i][j-money[i]])%mod;
        }
    }
    return dp[money.size()-1][n];
}
int solution(int n, vector<int> money) {
    init(n,money);//초기화
    return Change(n,money);//거스름 돈
}
