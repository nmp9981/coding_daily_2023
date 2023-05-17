#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 101;
int root[maxi];//각 노드의 루트 노드

//초기화
void init(int n){
    for(int i=0;i<n;i++) root[i] = i;
}
//2번째(비용) 기준 오름차순 정렬
bool cmp(vector<int> a,vector<int> b){
    if(a[2]<b[2]) return true;
    return false;
}
//루트노드 구하기
int Find(int r){
    if(root[r]==r) return r;
    return root[r] = Find(root[r]);
}
//합치기
void Merge(int a,int b){
    if(b>a) root[b] = a;
    else root[a] = b;
}
//크루스칼 알고리즘
int Kruskal(int n,vector<vector<int>> costs){
    sort(costs.begin(),costs.end(),cmp);//정렬
    
    int node = 0;
    int cost = 0;
    for(int i=0;i<costs.size();i++){
        int x = costs[i][0];
        int y = costs[i][1];
        int pay = costs[i][2];
        
        //루트노드 연결
        int a = Find(x);
        int b = Find(y);
        if(a!=b){
            Merge(a,b);
            node++;
            cost+=pay;
        }
        //모두 연결
        if(node==n-1) break;
    }
    return cost;
}
int solution(int n, vector<vector<int>> costs) {
    init(n);//초기화
    return Kruskal(n,costs);
}
