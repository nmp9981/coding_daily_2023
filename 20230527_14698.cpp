#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int n;
priority_queue<ll,vector<ll>,greater<ll>> pq;
const int mod = 1000000007;

//초기화
void init(){
    while(!pq.empty()) pq.pop();
}
//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        pq.push(x);
    }
}
//슬라임
void Slime(){
    ll total = 1;
    while(pq.size()>1){
        
        ll firstNum = pq.top();
        pq.pop();
        ll secondNum = pq.top();
        pq.pop();
        
        ll newNum = firstNum*secondNum;
        pq.push(newNum);
        newNum%=mod;
        total*=newNum;
        total%=mod;
    }
    cout<<total<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t;cin>>t;
    while(t--){
        init();//초기화
        input();//입력
        Slime();//슬라임
    }
    return 0;
}
