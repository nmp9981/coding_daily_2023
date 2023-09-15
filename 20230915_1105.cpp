#include <iostream>
using namespace std;

string l,r;
const int maxi = 301;
int A[maxi][maxi];//배열

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> l>>r;
    for (int i = 0; i < r.size() - l.size(); i++) l = '0' + l;
}
//8의 개수
int Count8() {
    int cnt = 0;
    for (int i = 0; i < r.size(); i++) {
        if (l[i] != r[i]) break;
        else if (l[i] == '8' && r[i] == '8') cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout<<Count8();//8의 개수
    return 0;
}
