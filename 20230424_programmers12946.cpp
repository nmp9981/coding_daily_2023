#include <string>
#include <vector>
using namespace std;

//하노이 탑
void Hanoi(vector<vector<int>>& answer,int n,int x,int y) {
    if(n==1){
        answer.push_back({x,y});
        return;
    }
    
    if (n > 1) Hanoi(answer,n - 1, x, 6 - x-y);
    answer.push_back({x,y});
    if (n > 1) Hanoi(answer,n - 1, 6 - x - y,y);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(answer,n,1,3);//하노이 탑
    return answer;
}
