#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxi = 201;
vector<int> graph[maxi];//그래프
bool visit[maxi];//방문 여부

//그래프 세팅
void SetGraph(int n,vector<vector<int>> computers){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]==1){//연결
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}
//연결
int Connect(int start){
    queue<int> q;
    visit[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        //다음 지점
        for(int i=0;i<graph[x].size();i++){
            int next = graph[x][i];
            if(visit[next]) continue;//방문 조건
            visit[next] = true;
            q.push(next);
        }
    }
    return 1;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    SetGraph(n,computers);//그래프 세팅
    for(int i=0;i<n;i++){//연결
        if(!visit[i]) answer+=Connect(i);
    }
    return answer;
}
