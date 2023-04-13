#include <string>
#include <vector>
using namespace std;

const int maxi = 200000001;
//max
inline int max(int x,int y){
    return x>y?x:y;
}
//연속하는 0의 개수
int ZeroCnt(vector<int> stones, int x){
    int cnt = 0;
    int maxCnt = 0;
    for(int i=0;i<stones.size();i++){
        int stone = stones[i]-x;
        if(stone<=0) {
            cnt++;
            maxCnt = max(maxCnt,cnt);
        }else cnt = 0;
    }
    return maxCnt;
}
//다리 건너기
int Bridge(vector<int> stones, int k){
    int start = 0;
    int end = maxi;
    int people = 0;//최대 인원 수
    
    while(start<=end){
        int mid = (start+end)/2;//인원 수
        if(ZeroCnt(stones,mid)<k){
            start = mid+1;//더 건너도됨
            people = max(people,mid);
        }else end = mid-1;//인원 줄여야함
    }
    return start;
}
int solution(vector<int> stones, int k) {
    return Bridge(stones,k);//다리 건너기
}
