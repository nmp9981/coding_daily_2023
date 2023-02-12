#include <string>
#include <vector>
using namespace std;

const int maxi =5000001;
int countDiv[maxi];//i의 약수의 개수
int manyNum[maxi];//i~e까지 가장 많이 등장하는 숫자

//약수의 개수 세기
void CountDiv(int e){
    for(int i=1;i<=e;i++) countDiv[1] = 1;//약수 1존재
    for(int i=2;i<=e;i++){
        for(int j=i;j<=e;j+=i) countDiv[j]++;
    }
}
//가장 많이 등장하는 숫자
void CountNum(int e){
    int num = 0;int idx = e;//횟수, i~e까지 가장 많이 등장한 숫자
    for(int i=e;i>=1;i--){
        if(num<=countDiv[i]){//갱신
            num = countDiv[i];
            idx = i;
        }
        manyNum[i] = idx;
    }
}
//가장 많이 등장하는  숫자
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    CountDiv(e);//약수의 개수 세기
    CountNum(e);//가장 많이 등장하는 숫자
    for(int i=0;i<starts.size();i++) answer.push_back(manyNum[starts[i]]);
    return answer;
}
