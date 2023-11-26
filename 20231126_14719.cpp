#include <iostream>
using namespace std;

int h,w;
const int maxi = 501;
int maxLength = 0;
int maxPos = 0;
int world[maxi];

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> h>>w;
    for (int i = 0; i < w; i++) {
        cin >> world[i];
        if (maxLength < world[i]) {
            maxLength = world[i];
            maxPos = i;
        }
    }
}
//수 나누기
void DivideNum() {
    int left = 0;//왼쪽 기준 기중
    int total = 0;
    int right = w - 1;//오른쪽 기준 기둥
    //왼쪽
    for (int i = 0; i < maxPos; i++) {
        if (world[i] < world[left]) total += (world[left] - world[i]);
        else left = i;//기준 기둥 변경
    }
    //오른쪽
    for (int i = w - 1; i > maxPos; i--) {
        if (world[i] < world[right]) total += (world[right] - world[i]);
        else right = i;
    }
    cout << total;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    DivideNum();//수 나누기
    return 0;
}
