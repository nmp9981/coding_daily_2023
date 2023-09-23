#include <iostream>
using namespace std;

//점 구조체
struct Point{
    double x,y;
};
int n;
const int maxi = 10001;
Point p[maxi];//다각형의 좌표

//입력
void input(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
}
//면적구하기
void Area(){
    //면적 구하기
    double surface = 0.0;
    for (int i = 1; i < n; i++){
        surface += ((p[i-1].x - p[0].x)*(p[i].y - p[0].y) - (p[i-1].y - p[0].y)*(p[i].x - p[0].x))/2;
    }
    surface*=surface<0?-1:1;//면적은 양수
    //소수점 첫째자리까지 출력
    cout<<fixed;
    cout.precision(1);
    cout<<surface;
}
int main()
{
    input();//입력
    Area();//면적구하기
    return 0;
}
