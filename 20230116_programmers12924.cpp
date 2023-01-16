#include <string>
#include <vector>

using namespace std;
const int maxi = 10001;

int solution(int n) {
    int answer = 0;
    int left = 1;int right = 1;
    int sum = 1;
    while(true){
        if(right>=maxi) break;//범위 초과
        if(sum>=n){//합이 n이상
            if(sum==n) answer++;//같다
            sum-=left;
            left++;
        }else{//합이 n미만
            right++;
            sum+=right;
        }
    }
    return answer;
}
