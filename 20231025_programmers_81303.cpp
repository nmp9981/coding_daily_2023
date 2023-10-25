#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
using namespace std;

set<int> table;//남은 행
stack<int> trash;//삭제된 행

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    //초기화
    for(int i=0;i<n;i++){
        table.insert(i);
        answer+='X';
    }

    auto iter = table.begin();
    while(k--) iter++;//k번 커서
    
    int amount =0;
    for(string c:cmd){
        char com = c[0];
        if(c.size()>1) amount =  stoi(c.substr(2));
        
        if(com=='U') while(amount--) iter--;
        else if(com=='D') while(amount--) iter++;
        else if(com=='C'){
            trash.push(*iter);
            iter = table.erase(iter);
            if(iter == table.end()) iter--;//마지막 페이지
        }else if(com=='Z'){
            table.insert(trash.top());
            trash.pop();
        }
    }
    
    for(int i:table) answer[i] = 'O';//존재하는 행은 O로
    return answer;
}
