#include <string>
#include <vector>
using namespace std;

const int maxi = 201;
const int inf = 333333333;
int cost[maxi][maxi];//i->j까지의 최소 비용

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = inf;
        }
    }
}
//그래프 세팅
void SetGraph(vector<vector<int>> fares){
    for(int i=0;i<fares.size();i++){
        int x = fares[i][0];
        int y = fares[i][1];
        int fee = fares[i][2];
        cost[x][y] = fee;
        cost[y][x] = fee;
    }
}
//플로이드
void Floyd(int n){
    for(int k=1;k<=n;k++){//경유 지점
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
        }
    }
}
//택시
int Taxi(int n,int s,int a,int b){
    int minCost = inf;//최소 요금
    for(int i=1;i<=n;i++) minCost = min(minCost,cost[s][i]+cost[i][a]+cost[i][b]);
    return minCost;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    init(n);//초기화
    SetGraph(fares);//그래프 세팅
    Floyd(n);//플로이드
    return Taxi(n,s,a,b);//택시
}
