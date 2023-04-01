#include <vector>
using namespace std;

const int maxi = 502;
int dp[maxi][maxi][2];//아래, 오른쪽
int MOD = 20170805;

//초기화
void init(int m, int n, vector<vector<int>> &world){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j][0] = 0;//아래
            dp[i][j][1] = 0;//오른쪽
        }
    }
    //아래
    for(int i=0;i<m;i++){
        if(world[i][0]==1) break;
        dp[i][0][0] = 1;
    }
    //오른쪽
    for(int j=0;j<n;j++){
        if(world[0][j]==1) break;
        dp[0][j][1] = 1;
    }
}
int Road(int m, int n, vector<vector<int>> &world){
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(world[i][j]==1) continue;//장애물
            
            //아래
            if(world[i-1][j]==2) dp[i][j][0] = dp[i-1][j][0];
            else dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][1])%MOD;
            //오른쪽
            if(world[i][j-1]==2) dp[i][j][1] = dp[i][j-1][1];
            else dp[i][j][1] = (dp[i][j-1][0]+dp[i][j-1][1])%MOD;
        }
    }
    return (dp[m-1][n-1][0]+dp[m-1][n-1][1])%MOD;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    init(m,n,city_map);//초기화
    return Road(m,n,city_map);
}
