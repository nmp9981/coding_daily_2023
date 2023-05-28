#include <string>
#include <vector>
using namespace std;

const int maxi = 100001;
const int inf = 1000000007;
int cost[101][maxi];

//거스름돈
int Change(int n,vector<int> money){
    //초기값
    for(int j=0;j<=n;j++){
        if((j%money[0])==0) cost[0][j] = 1;
    }
    //배낭 문제
    for(int i=1;i<=money.size();i++){
        for(int j=0;j<=n;j++){
            if(j < money[i]) cost[i][j] = cost[i-1][j];
            else cost[i][j] = (cost[i][j-money[i]]+cost[i-1][j])%mod;//쓴 경우 + 안쓴 경우
        }
    }
    return cost[money.size()-1][n];
}
int solution(int n, vector<int> money) {
    return Change(n,money);
}
