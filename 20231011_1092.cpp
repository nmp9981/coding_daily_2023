#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 10001;
vector<int> crain;//크레인
vector<int> box;//박스
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >>n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        crain.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int y; cin >> y;
        box.push_back(y);
    }
    //내림차순 정렬
    sort(crain.begin(), crain.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());
}
//옮기기
void Shift() {
    int times = 0;
    if (box[0] > crain[0]) cout << -1;//불가능(가장 큰거로도 못옮김)
    else {
        while (!box.empty()) {
            for (int i = 0; i < n; i++) {//각 크레인에 대해
                for (int j = 0; j < box.size(); j++) {//박스를 옮긴다.
                    if (crain[i] >= box[j]) {//옮길수 있음
                        box.erase(box.begin()+j);
                        break;//다음 크레인
                    }
                }
            }
            times++;
        }
        cout << times;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Shift();//옮기기
    return 0;
}
