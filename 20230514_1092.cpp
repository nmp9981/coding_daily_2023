#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> crain;//크레인
vector<int> box;//박스

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        crain.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        box.push_back(x);
    }
    //내림차순 정렬
    sort(crain.begin(), crain.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());
}
//옮기기
void Carry() {
    int times = 0;
    if (box[0] > crain[0]) cout << -1;//불가능
    else {
        while (!box.empty()) {
            for (int i = 0; i < n; i++) {//강한 크레인 부터
                for (int j = 0; j < box.size(); j++) {//상자를 옮긴다.
                    if (crain[i] >= box[j]) {//옮길 수 있다.
                        box.erase(box.begin() + j);//제거
                        break;//다음 크레인으로
                    }
                }
            }
            times++;
        }
        cout << times;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Carry();//옮기기
    return 0;
}
