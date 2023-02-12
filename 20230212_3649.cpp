#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x,n;
const int unitChange = 10000000;//단위 변환
vector<int> lego;//레고 조각 길이

//입력
void input() {
    lego.clear();//초기화
    for (int i = 0; i < n; i++) {
        int pe; cin >> pe;
        lego.push_back(pe);
    }
    sort(lego.begin(), lego.end());//오름차순 정렬
}
//막기
void Block() {
    int left = 0; int right = lego.size() - 1;
    while (left<right) {
        int sum = lego[left] + lego[right];
        if (sum == unitChange * x) {//구멍에 맞음
            cout << "yes " << lego[left] << " " << lego[right] << "\n";
            return;
        }
        else if (sum > unitChange * x) right--;//줄여야함
        else if (sum < unitChange * x) left++;//늘려야함
    }
    cout << "danger\n";//없음
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> x>>n) {
        input();//입력
        Block();//막기
    }
    return 0;
}
