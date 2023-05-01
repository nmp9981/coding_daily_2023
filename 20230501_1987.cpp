#include <iostream>
#include <queue>
using namespace std;

int r,c;
int ans = 1;
const int maxi = 21;
string world[maxi];
bool isAlpha[26];//알파벳 선택 여부
//4방 탐색
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//입력
void input(){
    cin>>r>>c;
    for(int i=0;i<r;i++) cin>>world[i];
    isAlpha[world[0][0]-'A'] = true;
}
//이동
void Move(int x,int y,int cnt){
    ans = max(ans,cnt);//갱신
    
    //다음 지점
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx>=r || ny<0 || ny>=c) continue;//범위 조건
        if(isAlpha[world[nx][ny]-'A']) continue;//방문 조건
        
        isAlpha[world[nx][ny]-'A'] = true;
        Move(nx,ny,cnt+1);
        isAlpha[world[nx][ny]-'A'] = false;
    }
}
int main()
{
    input();//입력
    Move(0,0,1);//이동
    cout<<ans;
    return 0;
}
