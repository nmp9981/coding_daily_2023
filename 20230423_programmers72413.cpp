#include <string>
#include <vector>
using namespace std;

const int maxi = 201;
const int inf = 700000001;
int dist[maxi][maxi];//a->b까지의 최소 거리

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(int n,vector<vector<int>> fares){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
    for(int i=0;i<fares.size();i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
}

//플로이드
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
}
//택시
int taxi(int n, int s, int a, int b){
    int cost = inf;
    for(int i=1;i<=n;i++){//내리는 지점
        cost = min(cost,dist[s][i]+dist[i][a]+dist[i][b]);
    }
    return cost;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    init(n,fares);//초기화
    floyd(n);//플로이드
    return taxi(n,s,a,b);//택시
}
