#include <iostream>
#include <cstring>
using namespace std;

int n;
const int maxi = 1001;
const int inf = 1e+8;
int house[maxi][3];//가격
int dp[maxi][3];//누적 가격

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>house[i][0]>>house[i][1]>>house[i][2];
    }
}

//색상 선택
int color(int start){
    memset(dp,0,sizeof(dp));
    //2번집
    for(int i=0;i<3;i++){
        if(i==start){//1번과 같은색이므로 칠할 수 없음
            dp[2][start] = inf;
        }else{
            dp[2][i] = house[1][start] + house[2][i];
        }
    }
    //i번집
    for(int i=3;i<=n;i++){
        dp[i][0] = house[i][0] + min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = house[i][1] + min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = house[i][2] + min(dp[i-1][0],dp[i-1][1]);
    }
    //n번집은 1번 집과 색상이 겹치면 안된다.
    int cost = inf;
    for(int i=0;i<3;i++){
        if(i!=start){
            cost = min(cost,dp[n][i]);
        }
    }
    return cost;
}
int main(){
    input();//입력
    int ans = inf;
    for(int i=0;i<3;i++){//1번집을 어떤 색으로 칠하는가?
        ans = min(ans,color(i));
    }
    cout<<ans;
    return 0;
}
