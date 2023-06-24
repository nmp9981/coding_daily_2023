#include <iostream>
using namespace std;

int n,m;
const int maxi = 5;
int board[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
int maxAttack = 0;//총 공격력
//동남서북
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,-1,1};

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//입력
void input(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>board[i][j];
    }
}

//무기 공격력
void Weapon(int r,int c,int attack){
    //다음 행
    if(c==m){
        c = 0;
        r++;
    }
    //종료
    if(r==n){
        maxAttack = max(attack,maxAttack);
        return;
    }
    //4방 탐색
    if(!visit[r][c]){
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;//범위 조건
            if(visit[r][nc]) continue;//방문 조건
            if(visit[nr][c]) continue;
            
            //방문 체크
            visit[r][c] = true;
            visit[r][nc] = true;
            visit[nr][c] = true;
            
            int newAttack = 2*board[r][c]+board[nr][c]+board[r][nc];//새 공격력
            Weapon(r,c+1,attack+newAttack);
            
            //체크 해제
            visit[r][c] = false;
            visit[r][nc] = false;
            visit[nr][c] = false;
        }
    }
    Weapon(r,c+1,attack);//다음으로
}
int main()
{
    input();//입력
    if(n==1 || m==1) cout<<0;//크기 미달
    else{
        Weapon(0,0,0);//무기
        cout<<maxAttack;
    }
    return 0;
}
