#include <iostream>
#include <vector>
using namespace std;

//계란 정보
struct Egg {
    int hp, atk;
};
int n;
int ans = 0;
vector<Egg> egg;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, w;
        cin >> s >> w;
        egg.push_back({ s,w });
    }
}
//계란 깨기
void breakEgg(int idx) {//가장 왼쪽 계란
    //깨진 계란의 개수 세기
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (egg[i].hp <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    
    //공격 대상
    bool flag = false;//깰 수 있는가?
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;//자기 자신
        if (egg[i].hp > 0 && egg[idx].hp>0) {//공격 가능
            flag = true;
            egg[idx].hp -= egg[i].atk;
            egg[i].hp -= egg[idx].atk;
            breakEgg(idx + 1);//다음 계란
            egg[idx].hp += egg[i].atk;
            egg[i].hp += egg[idx].atk;
        }
    }
    if(!flag) breakEgg(idx + 1);//다음 계란
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    breakEgg(0);//계란 깨기
    cout << ans;//출력
    return 0;
}
