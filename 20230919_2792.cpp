#include <iostream>
using namespace std;

int n,m;
const int maxi = 300001;
int candy[maxi];//사탕 개수

//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>candy[i];
}
//min
inline int min(int x,int y){
    return x>y?y:x;
}

//질투심
int Envy(int x){
    int total = 0;
    for(int i=0;i<m;i++) {
        total+=((candy[i]-1)/x+1);
    }
    return total;
}
//나누기
void Divide(){
    int start = 1;
    int ans = 1000000000;
    int end = ans;
    while(start<=end){
        int mid = (start+end)/2;
        if(Envy(mid)>n) start = mid+1;
        else {
            end = mid-1;
            ans = min(ans,end);
        }
    }
    cout<<ans+1;
}

int main()
{
    input();//입력
    Divide();//나누기
    return 0;
}
