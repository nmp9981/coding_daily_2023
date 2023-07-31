#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> wears;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0;i<clothes.size();i++) wears[clothes[i][1]]++;
    for(auto a:wears) answer*=(a.second+1);
    return answer-1;//아무것도 안입는거 제외
}
