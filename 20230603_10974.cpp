#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
const int maxi = 9;
vector<int> v;
bool visit[maxi] = { false, };

//입력
void input() {
    cin >> n;
}
//순열
void Permunitation(int cnt) {
    //출력
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    //다음 숫자
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;

        v.push_back(i);
        visit[i] = true;
        Permunitation(cnt + 1);
        visit[i] = false;
        v.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Permunitation(0);//순열
    return 0;
}
