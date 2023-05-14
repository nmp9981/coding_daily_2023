#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const int maxi = 100001;
ll Tile[maxi];//타일 덮는 총 경우의 수
ll addTile[maxi];//한번에 덮는 추가량
const ll mod = 1000000007;

//타일 덮기
void TileCover(){
    Tile[0] = 1;
    Tile[1] = 1;
    Tile[2] = 3;
    for(int i=3;i<maxi;i++){
        Tile[i] = Tile[i-1]+2*Tile[i-2]+5*Tile[i-3];
        if(i>=4){
            if(i==4) addTile[i] = 2;
            else if(i==5) addTile[i] = 4;
            else addTile[i] = 2*Tile[i-4]+2*Tile[i-5]+4*Tile[i-6]+addTile[i-3];
        }
        Tile[i] += addTile[i];
        Tile[i]%=mod;
    }
}
int solution(int n) {
    TileCover();//타일 덮기
    return Tile[n];
}
