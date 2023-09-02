#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 100001;
int dp[maxi];

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//입력
void input(){
    cin>>n;
}
//초기화
void init(){
    for(int i=0;i<maxi;i++) dp[i] = i;
}
//제곱수
void Square(){
    for(int i=4;i<=n;i++){
        int j = 1;
        while(i>=j*j){
            dp[i] = min(dp[i-j*j]+1,dp[i]);
            j++;
        }
    }
    cout<<dp[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    init();//초기화
    input();//입력
    Square();//제곱수
    return 0;
}
