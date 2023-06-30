#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int n,m,k;
const int maxi = 11;
string world[maxi];//지도
map<string, int> wordCount;//각 단어의 개수
//8방 탐색
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int dy[8] = { -1,1,0,0,1,1,-1,-1 };

//입력
void input() {
    cin >> n>>m>>k;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//단어 세기
void WordCount(int x,int y,string str, int cnt) {
    if (cnt >= 5) return;//길이 초과
    wordCount[str]++;
    
    //다음 글자
    for (int k = 0; k < 8; k++) {
        int nx = (x + dx[k]+n)%n;
        int ny = (y + dy[k]+m)%m;

        WordCount(nx, ny, str + world[nx][ny], cnt + 1);
    }
}
//질문
void Question() {
    for (int i = 0; i < k; i++) {
        string s; cin >> s;
        cout << wordCount[s] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string newWord = "";
            WordCount(i, j, newWord+world[i][j] , 0);//단어 세기 
        }
    }
    Question();//질문
    return 0;
}
