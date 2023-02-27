#include <string>
using namespace std;

//엘리베이터
int Elevators(int start){
    int cnt = 0;
    while(start>0){
        int next = start%10;
        if(next>5){//올라감
            start+=(10-next);
            cnt+=(10-next);
        }else if(next==5 && (start/10)%10>=5){
            start+=(10-next);
            cnt+=(10-next);
        }else cnt+=next;//내려감
        
        start/=10;
    }
    return cnt;
}
int solution(int storey) {
    return Elevators(storey);
}
