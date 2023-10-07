#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace:std;

int n;
vector<pair<int,int>> lecture;//강의


//입력
void input(){
  cin>>n;
  for(int i=0;i<n;i++){
    int s,t;
    cin>>s>>t;
    lecture.push_back({s,t});
  }
  sort(lecture.begin(),lecture.end());//정렬
}

//교실 배정
void ClassRoom(){
  int cnt = 1;
  queue<int,vector<int> greater<int>> pq;//종료 시각
  pq.push(lecture[0].second);
  for(int i=1;i<n;i++){
    int startTime = lecture[i].first;
    int endTime = lecture[i].second;

    if(startTime<pq.top()) cnt++;
    else pq.pop();
    pq.push(endTime);
  }
  cout<<cnt;
}
int main(){
  input();//입력
  ClassRoom();//교실 배정
  return 0;
}
