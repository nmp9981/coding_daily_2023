#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll sum =0;
const ll mod = 1000000007;
const int maxi = 1000001;
ll tile[maxi];//타일채우는 경우의 수

//입력
void input(){
    cin>>n;
}
//채우기
void Fill(){
    tile[0] = 1;
    tile[1] = 2;
    tile[2] = 7;
    for(int i=3;i<=n;i++){
        sum+=(2*tile[i-3]); 
        tile[i] = (2*tile[i-1]+3*tile[i-2]+sum)%mod;
    }
    cout<<tile[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    input();//입력
    Fill();//채우기
    return 0;
}
