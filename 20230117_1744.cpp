#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 51;
vector<int> posi;//+수열
vector<int> nega;//-수열
int one=0;//1의 개수

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 1) posi.push_back(x);
        else if (x == 1) one++;
        else if (x < 1) nega.push_back(x);
    }
    if(posi.size()>0) sort(posi.begin(), posi.end());//정렬
    if(nega.size()>0) sort(nega.begin(), nega.end());
}
//덧셈
void Add() {
    int sum = 0;
    //+
    if (posi.size() & 1) sum += posi[0];
    if (posi.size() >= 2) {
        for (int i = posi.size() - 1; i >= 1; i -= 2) sum += (posi[i] * posi[i - 1]);
    }
    //-
    if (nega.size() & 1) sum += nega[nega.size() - 1];
    if (nega.size() >= 2) {
        for (int i = 0; i < nega.size() - 1; i += 2) sum += (nega[i] * nega[i + 1]);
    }
    //1
    sum += one;
    cout << sum;//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Add();//덧셈
    return 0;
}
