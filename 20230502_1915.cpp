#include <iostream>
#include <vector>
using namespace std;

int n,m;
int maxArea = 0;
const int maxi = 1001;
string world[maxi];
int area[maxi][maxi];

//min
inline int min(int x,int y){
    return x>y?y:x;
}
//max
inline int max(int x,int y){
    return x>y?x:y;
}
//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>world[i];
}
//정사각형 넓이
void Square(){
    for(int i=0;i<n;i++){
        if(world[i][0]=='1'){
            area[i][0] = 1;
            maxArea = 1;
        }else area[i][0] = 0;
    }
    for(int j=0;j<m;j++){
        if(world[0][j]=='1'){
            area[0][j] = 1;
            maxArea = 1;
        }else area[0][j] = 0;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(world[i][j]=='1'){
                area[i][j] = 1+min(area[i-1][j],min(area[i][j-1],area[i-1][j-1]));
                maxArea = max(maxArea,area[i][j]);
            }
        }
    }
    cout<<maxArea*maxArea;
}
int main()
{
    input();//입력
    Square();//정사각형 넓이
    return 0;
}
