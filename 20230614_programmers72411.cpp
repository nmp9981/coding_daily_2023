#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int maxi = 11;
map<string,int> worldCnt;//각 단어가 몇번 나왔는가?
int maxCnt[maxi];//i자리수에서의 최대 자릿수
vector<string> menu[maxi];//각 자릿수별 메뉴

//단어 조합
void WordCombi(string order,int idx,string word){
    if(word.size()>=2){
        worldCnt[word]++;
        if(worldCnt[word] > maxCnt[word.size()]) maxCnt[word.size()] = worldCnt[word];//최대 등장횟수
    }
    //다음 글자
    for(int i=idx;i<order.size();i++){
        string nextWord = word+order[i];
        WordCombi(order,i+1,nextWord);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //단어 조합
    for(string order:orders){
        sort(order.begin(),order.end());
        WordCombi(order,0,"");
    }
    //메뉴 구하기
    for(int i:course){
        if(maxCnt[i]>=2){
            for(auto w:worldCnt){
                if(w.second==maxCnt[i] && w.first.size()==i) answer.push_back(w.first);
            }
        }
    }
    sort(answer.begin(),answer.end());//오름차순 정렬
    return answer;
}
