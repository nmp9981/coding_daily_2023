#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 51;
const int inf = 1000000;
int score[maxi][maxi];//i,j사이 점수
int candidate[maxi];//각 후보별 점수

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    //초기화
    for (int i = 1; i <= n; i++) {
        candidate[i] = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) score[i][j] = 0;
            else score[i][j] = inf;
        }
    }
    //입력
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        //친구관계
        score[a][b] = 1;
        score[b][a] = 1;
    }
}
//플로이드
void Floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) score[i][j] = min(score[i][j], score[i][k] + score[k][j]);
        }
    }
}
//대장 후보
void Captain() {
    for (int i = 1; i <= n; i++) {
        //각 후보별 검사
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;//자기자신
            if (candidate[i] < score[i][j]) candidate[i] = score[i][j];
        }
    }
    //대장 후보
    int captainScore = inf;
    vector<int> captain;
    for (int i = 1; i <= n; i++) {
        if (captainScore > candidate[i]) {
            captainScore = candidate[i];
            captain.clear();
        }
        if (captainScore == candidate[i]) captain.push_back(i);
    }
    //출력
    cout << captainScore << " " << captain.size() << "\n";
    for (int i = 0; i < captain.size(); i++) cout << captain[i] << " ";
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Floyd();//플로이드
    Captain();//대장 후보
    return 0;
}
