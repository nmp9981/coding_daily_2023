#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> liquid;//무게

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        liquid.push_back(x);
    }
    sort(liquid.begin(), liquid.end());//오름차순 정렬
}
//용액제작
void MakeLiquid() {
    int result = abs(liquid[n - 1] + liquid[0]);//결과
    int left = 0; int right = n - 1;
    int ans1 = 0; int ans2 = n - 1;
    while (left < right) {
        if (0 == liquid[right] + liquid[left]) {
            cout << liquid[left] << " " << liquid[right] << "\n";
            return;
        }
        //더 작은 값
        if (result > abs(liquid[right] + liquid[left])) {
            result = abs(liquid[right] + liquid[left]);
            ans1 = left;
            ans2 = right;
        }
        //포인터 이동
        else if (0 < liquid[right] + liquid[left]) right--;
        else left++;
    }
    cout << liquid[ans1] << " " << liquid[ans2];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MakeLiquid();//용액제작
    return 0;
}
