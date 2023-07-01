#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int n;
const int maxi = 5;
string board[maxi];//보드
string semiBoard[maxi];//각 칸별
vector<int> number[9];//각 자릿수별 올 수있는 숫자
//각 숫자별 기준
string num[10][5] = 
{ {"###","#.#","#.#","#.#","###"},//0
    {"..#","..#","..#","..#","..#"}, //1
{"###","..#","###","#..","###"}, //2
{"###","..#","###","..#","###"}, //3
{"#.#","#.#","###","..#","..#"}, //4
{"###","#..","###","..#","###"}, //5
{"###","#..","###","#.#","###"}, //6
{"###","..#","..#","..#","..#"}, //7
{"###","#.#","###","#.#","###"}, //8
{"###","#.#","###","..#","###"}};//9
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < maxi; i++) cin >> board[i];
}
//나올 수 있는 숫자
void Bulb(int k) {
    for (int digit = 0; digit < 10; digit++) {
        bool isPossi = true;
        for (int i = 0; i < maxi; i++) {
            for (int j = 0; j < 3; j++) {
                if (num[digit][i][j] == '.' && semiBoard[i][j] == '#') isPossi = false;//변환 불가
            }
        }
        if (isPossi) number[k].push_back(digit);
    }
}
//각 칸별 체크
void Check() {
    for (int k = 0; k < n; k++) {
        int startCol = 4 * k;
        for (int i = 0; i < maxi; i++) semiBoard[i] = board[i].substr(startCol, 3);
        Bulb(k);//전구
    }
}
//평균
void Average() {
    int numSize = 1;
    for (int k = 0; k < n; k++) numSize *= number[k].size();

    if (numSize == 0) cout << -1;//가능한 번호가 없다.
    else {
        double total = 0.0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < number[i].size(); j++) sum += number[i][j];
            total += ((double)sum / (double)number[i].size()) * pow(10, n-i-1);
        }
        cout << total;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Check();//각 칸별 체크
    Average();//평균
    return 0;
}
