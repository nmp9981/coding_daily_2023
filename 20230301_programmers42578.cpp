#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0;i<clothes.size();i++) m[clothes[i][1]]++;//옷종류
    for(auto i:m) answer*=(i.second+1);
    return answer-1;//전부 안입는거 제외
}
