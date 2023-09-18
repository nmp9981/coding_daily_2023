#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> schedule;//스케줄

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        schedule.push_back({a,b});
    }
    sort(schedule.begin(),schedule.end());//시작시간 순으로 정렬
}
//교실
void Classroom(){
    int cnt = 1;
    priority_queue<int,vector<int>,greater<int>> pq;//최소힙
    pq.push(schedule[0].second);//종료 시간
    
    for(int i=1;i<schedule.size();i++){
        int startTime = schedule[i].first;
        int endTime = schedule[i].second;
        
        //종료시각보다 늦으면 늘림
        if(startTime<pq.top()) cnt++;
        else pq.pop();
        
        pq.push(endTime);
    }
    cout<<cnt;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();//입력
    Classroom();//교실
    return 0;
}
