#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
vector<pair<int,pair<int,int>>> graph;//그래프
int root[maxi];//각노드의 루트노드

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph.push_back({c,{a,b}});
    }
    sort(graph.begin(),graph.end());//거리순 정렬
}
//초기화
void init(){
    for(int i=0;i<maxi;i++) root[i] = i;
}
//루트노드 구하기
int Find(int k){
    if(root[k]==k) return k;
    return root[k] = Find(root[k]);
}
//병합
void Merge(int mx,int my){
    if(mx>my) root[mx] = my;
    else root[my] = mx;
}
//스패닝트리
void Spaning(){
    int total = 0;
    int node = 0;
    for(int i=0;i<m;i++){
        int cost = graph[i].first;
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        
        int rx = Find(x);
        int ry = Find(y);
        if(rx!=ry){
            Merge(rx,ry);
            node++;
            total+=cost;
        }
        if(node==n-1){
            cout<<total;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    init();//초기화
    input();//입력
    Spaning();//스패닝트리
    return 0;
}
