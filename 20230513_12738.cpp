#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
}

//LIS
void LIS(){
    vector<int> v;
    for(int i=0;i<n;i++){
        if(v.size() == 0 || v[v.size()-1] < A[i]) v.push_back(A[i]);
        else{
            int pos = lower_bound(v.begin(),v.end(),A[i]) - v.begin();
            v[pos] = A[i];
        }
    }
    cout<<v.size();
}
int main()
{
    input();//입력
    LIS();//LIS
    return 0;
}
