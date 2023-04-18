#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int maxi = 500001;
int n;
long long plusPerse[maxi];//1시작
long long minusPerse[maxi];//-1시작
long long CsumPlus[maxi];//1시작 누적합
long long CsumMinus[maxi];//-1시작 누적합

//max
inline long long max(long long x,long long y){
    return x>y?x:y;
}
//min
inline long long min(long long x,long long y){
    return x>y?y:x;
}
//수열 세팅
void Setting(vector<int> s){
    n = s.size();
    for(int i=0;i<n;i++){
        plusPerse[i] = s[i]*pow(-1,i+2);
        minusPerse[i] = s[i]*pow(-1,i+1);
    }
}
//누적합
void Csum(){
    CsumPlus[0] = plusPerse[0];
    CsumMinus[0] = minusPerse[0];
    for(int i=1;i<n;i++){
        CsumPlus[i] = plusPerse[i]+CsumPlus[i-1];
        CsumMinus[i] = minusPerse[i]+CsumMinus[i-1];
    }
}
//펄스 수열
long long Perse(){
    long long maxSum1 = CsumPlus[n-1];
    long long minSum1 = 0;
    long long maxSum2 = CsumMinus[n-1];
    long long minSum2 = 0;
    
    //1시작
    int plusIdx = n-1;
    for(int i=n-1;i>=0;i--){
        if(maxSum1<CsumPlus[i]){
            maxSum1 = CsumPlus[i];
            plusIdx = i;
        }
    }
    for(int i=0;i<plusIdx;i++) minSum1 = min(minSum1,CsumPlus[i]);
    
    //-1시작
    int minusIdx = n-1;
    for(int i=n-1;i>=0;i--){
        if(maxSum2<CsumMinus[i]){
            maxSum2 = CsumMinus[i];
            minusIdx = i;
        }
    }
    for(int i=0;i<minusIdx;i++) minSum2 = min(minSum2,CsumMinus[i]);
    
    return max(maxSum1-minSum1,maxSum2-minSum2);
}
long long solution(vector<int> sequence) {
    Setting(sequence);//수열 세팅
    Csum();//누적합
    return Perse();//펄스 수열
}
