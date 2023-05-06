#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, int>> score;//성적

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    score.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        score.push_back({ a,b });
    }
    sort(score.begin(), score.end());//서류순 정렬
}

//선발
void Pick() {
    int people = 1;
    int maxRank = score[0].second;
    for (int i = 1; i < n; i++) {
        if (maxRank > score[i].second) {
            people++;
            maxRank = score[i].second;
        }
    }
    cout << people << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        Pick();//선발
    }
    return 0;
}
