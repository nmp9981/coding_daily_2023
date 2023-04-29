#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int inf = 2100000000;
vector<int> liquid;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        liquid.push_back(x);
    }
    sort(liquid.begin(), liquid.end());//오름 차순 정렬
}
//선택
void Select() {
    int left = 0;
    int right = n - 1;
    int set1 = 0;
    int set2 = n - 1;
    int diff = inf;
    while (left < right) {
        if (liquid[left] + liquid[right] == 0) {
            cout << liquid[left] << " " << liquid[right];
            return;
        }
        if (abs(liquid[left] + liquid[right]) < diff) {
            diff = abs(liquid[left] + liquid[right]);
            set1 = left;
            set2 = right;
        }

        if (liquid[left] + liquid[right] > 0) right--;
        else left++;
    }
    cout << liquid[set1] << " " << liquid[set2];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Select();//선택
    return 0;
}
