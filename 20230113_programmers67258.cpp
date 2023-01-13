#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int jewelSize;//보석 개수
const int inf = 100000000;
set<string> display;//진열된 보석
map<string,int> jewel;//각 보석의 개수
vector<int> answer;//정답

//보석 모으기
void collection(vector<string> &gems){
    for(int i=0;i<gems.size();i++){
        display.insert(gems[i]);
        jewel[gems[i]] = 0;
    }
    jewelSize = display.size();
}
//쇼핑하기
void shopping(vector<string> &gems){
    int left,right;//최종 선택 위치
    int buyLen = inf;//구매 길이
    int buyCnt = 0;//구매 개수
    int start = 0;int end = 0;//현재 선택 위치
    while(true){//end 기준
        if(jewelSize==buyCnt){
            //구매 개수 갱신
            if(buyLen>end-start){
                buyLen = end-start;
                right = end;
                left = start;
            }
            //start 이동
            if(jewel[gems[start]]==1) buyCnt--;//보석 종류가 없어짐
            jewel[gems[start]]--;//보석 개수 감소
            start++;
        }else if(end==gems.size()) break;    
        else{
            if(jewel[gems[end]]==0) buyCnt++;//새로운 보석
            jewel[gems[end]]++;
            end++;
        }
    }
    //정답 
    answer.push_back(left+1);
    answer.push_back(right);
}
vector<int> solution(vector<string> gems) {
    collection(gems);//보석 모으기
    shopping(gems);//쇼핑하기
    return answer;
}
