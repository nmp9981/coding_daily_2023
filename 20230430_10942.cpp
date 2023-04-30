#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
const int maxi = 2001;
int A[maxi];//수열
bool isPalin[maxi][maxi];//i~j까지가 팰린드롬인가?

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        isPalin[i][i] = true;
    }
}

//팰린드롬
void Palindrome() {
    //2자리
    for (int i = 1; i < n; i++) {
        if (A[i] == A[i + 1]) isPalin[i][i + 1] = true;
    }
    //팰린드롬 검사
    for (int s = 3; s <= n; s++) {//길이
        for (int i = 1; i <= n - s+1; i++) {//시작 지점
            if (A[i] == A[i + s - 1]) {//양끝이 같고
                if (isPalin[i + 1][i + s - 2]) isPalin[i][i + s - 1] = true;
            }
        }
    }
}
//질문
void Question() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << isPalin[s][e] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Palindrome();//팰린드롬
    Question();//질문
    return 0;
}
