#include <iostream>
using namespace std;

int n,m,st,ed;
const int inf = 1000000000;
const int maxi = 100001;
int ray[maxi];//블루레이

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        cin >> ray[i];
        st = max(st, ray[i]);
        ed += ray[i];
    }
}
//블루레이 개수
int RayCount(int x) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ray[i];
        if (sum > x) {
            cnt++;
            sum = ray[i];
        }
    }
    return cnt;
}
//블루레이
void BlueRay() {
    int left = st;
    int right = ed;

    while (left <= right) {
        int mid = (left + right) / 2;//블루레이 최대 크기
        if (RayCount(mid) > m) left = mid + 1;//늘려야함
        else right = mid - 1;//줄여야함
    }
    cout << left;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    BlueRay();//블루레이
    return 0;
}
