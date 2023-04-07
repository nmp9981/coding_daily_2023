#include <string>
#include <vector>
#include <queue>
using namespace std;

const int maxi = 51;
bool visit[maxi];//각 단어 방문 여부

//단어 차이 개수
int Diff(string nextWord, string word){
    int diffCount = 0;
    for(int i=0;i<word.size();i++){
        if(word[i] != nextWord[i]) diffCount++;
    }
    return diffCount;
}
//단어 바꾸기
int ChangeWord(string begin, string target, vector<string> words){
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while(!q.empty()){
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        //목표 도착
        if(word==target) return cnt;
        
        //다음 단어
        for(int i=0;i<words.size();i++){
            string nextWord = words[i];
            if(visit[i]) continue;//방문 여부
            if(word == nextWord) continue;//같은 단어
            
            int diffSize = Diff(nextWord,word);//단어 차이 개수
            if(diffSize==1){//개수 차이가 1이면
                visit[i] = true;
                q.push({nextWord,cnt+1});
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    return ChangeWord(begin,target,words);//단어 바꾸기
}
