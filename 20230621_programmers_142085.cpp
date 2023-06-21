#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int>pq;//최소힙
//공격
int Attack(int n,int k,vector<int> enemy){
    int sum = 0;
    for(int i=0;i<enemy.size();i++){
        pq.push(enemy[i]);
        sum+=enemy[i];
        
        //무적권
        if(sum>n){
            if(k==0) return i;//사용불가
            k--;
            sum-=pq.top();
            pq.pop();
        }
    }
    return enemy.size();//모두 클리어
}
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    return Attack(n,k,enemy);//공격
}
