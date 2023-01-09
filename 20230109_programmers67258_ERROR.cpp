#include <string>
#include <vector>
#include <map>
using namespace std;

int minLen;//최소 구간 길이
vector<string> gemstone;//보석 배열
map<string,int> jewel;//보석 종류, 개수
vector<int> answer;//정답 벡터

//보석 개수 세기
void JewelCount(vector<string> &gems){
    gemstone = gems;
    for(int i=0;i<gemstone.size();i++) jewel[gemstone[i]]++;
}
//쇼핑
void Shopping(){
    int start = 0;//시작 위치
    int end = gemstone.size()-1;//종료 위치
    bool endflag = false;bool startflag = false;//탐색 종료여부
    //끝지점
    while(!endflag){
        if(jewel[gemstone[end]]>1){
            jewel[gemstone[end]]--;
            end--;
        }else endflag = true;//쇼핑 불가
    }
    //시작 지점
    while(!startflag){
        if(jewel[gemstone[start]]>1){
            jewel[gemstone[start]]--;
            start++;
        }else startflag = true;//쇼핑 불가
    }
    answer.push_back(start+1);
    answer.push_back(end+1);
}
vector<int> solution(vector<string> gems) {
    JewelCount(gems);//보석 개수 세기
    Shopping();//쇼핑
    return answer;
}
