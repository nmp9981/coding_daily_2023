#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;//최소 힙

//세팅
void Setting(vector<int> B){
    for(int i=0;i<B.size();i++) pq.push(B[i]);
}
//플레이
int Play(vector<int> A){
    int win = 0;
    for(int i=0;i<A.size();i++){
        while(!pq.empty() && A[i]>=pq.top()) pq.pop();//방출
        
        if(pq.size()==0) break;//모두 검사
        win++;//득점
        pq.pop();
    }
    return win;
}
int solution(vector<int> A, vector<int> B) {
    sort(A.begin(),A.end());//오름차순 정렬
    Setting(B);//세팅
    return Play(A);//플레이
}
