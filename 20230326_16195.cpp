#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1000000009;
const int maxi = 1001;
ll dp[maxi][maxi];
int t,a,b;

//더하기
void Add123(){
    dp[1][1] = 1;dp[2][1] = 1;dp[2][2] = 1;
    dp[3][1] = 1;dp[3][2] = 2;dp[3][3] = 1;
    for(int i=4;i<maxi;i++){
        for(int j=1;j<=i;j++) dp[i][j] = (dp[i-1][j-1]+dp[i-2][j-1]+dp[i-3][j-1])%mod;
    }
}
int main()
{
    Add123();
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll csum = 0;
        for(int i=1;i<=b;i++) csum+=dp[a][i];
        cout<<csum%mod<<"\n";
    }
    return 0;
}
