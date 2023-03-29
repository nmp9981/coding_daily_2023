#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<int> LisLen;//LIS길이
vector<pair<int, int>> line;
vector<int> Lis;
vector<int> cut;

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        line.push_back({ a,b });
    }
    sort(line.begin(), line.end());//오름차순 정렬
}
//LIS
void LIS() {
    Lis.push_back(line[0].second);
    LisLen.push_back(0);
    for (int i = 1; i < n; i++) {
        if (Lis[Lis.size() - 1] < line[i].second) {
            Lis.push_back(line[i].second);
            LisLen.push_back(Lis.size()-1);
        }
        else {
            int pos = lower_bound(Lis.begin(), Lis.end(), line[i].second)-Lis.begin();
            Lis[pos] = line[i].second;
            LisLen.push_back(pos);
        }
    }
    cout << n-Lis.size() << "\n";//잘라야하는 길이
}
//전선 자르기
void CutLine() {
    int len = Lis.size()-1;
    for (int i = n - 1; i >= 0; i--) {
        if (LisLen[i]==len) len--;
        else cut.push_back(line[i].first);
    }
    sort(cut.begin(), cut.end());
    for (int i = 0; i < cut.size(); i++) cout << cut[i] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    LIS();//LIS
    CutLine();//전선 자르기
    return 0;
}
