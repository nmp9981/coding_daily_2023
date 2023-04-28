#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r,c,k;
int rowSize, colSize;
const int maxi = 101;
const int inf = 555555555;
int A[maxi][maxi];//배열
int numCnt[maxi];//각 숫자별 등장 횟수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> A[i][j];
    }
}
//R
void R(int rowSize) {
    //각 행에 대해
    for (int i = 0; i < rowSize; i++) {
        //등장 횟수 초기화
        for (int j = 0; j < maxi; j++) numCnt[j] = 0;

        //수와 등장횟수 구하기
        for (int j = 0; j < colSize; j++) {
            if (j == 100) break;//범위 초과
            numCnt[A[i][j]]++;
        }
        vector<pair<int, int>> comp;//횟수, 숫자
        for (int j = 1; j <= 100; j++) {
            if (numCnt[j] >= 1) comp.push_back({ numCnt[j],j });
        }
        sort(comp.begin(), comp.end());//정렬
        //정렬 결과 넣기
        for (int j = 0; j < comp.size(); j++) {
            A[i][2*j] = comp[j].second;
            A[i][2*j+1] = comp[j].first;
        }
        colSize = max(colSize, 2 * comp.size());
        for (int j = 2 * comp.size(); j < colSize; j++) A[i][j] = 0;//뒷부분 0
        if (colSize > 100) colSize = 100;//범위 초과
    }
}
//C
void C(int colSize) {
    //각 열에 대해
    for (int j = 0; j < colSize; j++) {
        //등장 횟수 초기화
        for (int i = 0; i < maxi; i++) numCnt[i] = 0;

        //수와 등장횟수 구하기
        for (int i = 0; i < rowSize; i++) {
            if (i == 100) break;//범위 초과
            numCnt[A[i][j]]++;
        }
        vector<pair<int, int>> comp;//횟수, 숫자
        for (int i = 1; i <= 100; i++) {
            if (numCnt[i] >= 1) comp.push_back({ numCnt[i],i });
        }
        sort(comp.begin(), comp.end());//정렬
        //정렬 결과 넣기
        for (int i = 0; i < comp.size(); i++) {
            A[2*i][j] = comp[i].second;
            A[2*i+1][j] = comp[i].first;
        }
        rowSize = max(rowSize, 2 * comp.size());
        for (int i = 2 * comp.size(); i < rowSize; i++) A[i][j] = 0;//뒷부분 0
        if (rowSize > 100) rowSize = 100;//범위 초과
    }
}
//연산
void Cal() {
    rowSize = 3; colSize = 3;
    for (int t = 0; t <= 100; t++) {
        //종료조건
        if (A[r-1][c-1] == k) {
            cout << t;
            return;
        }
        //RC
        if (rowSize >= colSize) R(rowSize);
        else C(colSize);
    }
    cout << -1;//시간 초과
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Cal();//연산
    return 0;
}
