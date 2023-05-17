#include <iostream>
#include <vector>
using namespace std;

//계란 정보
struct EggInfo{
    int HP, Attack;
};
int n;
int ans = 0;//정답
vector<EggInfo> Egg;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int hp, attack;
        cin >> hp >> attack;
        Egg.push_back({ hp,attack });
    }
}
//계란깨기
void EggBreak(int idx) {
    if (idx == n) {//가장 오른쪽
        //개수 세기
        int breakCount = 0;//깨진 계란의 수
        for (int i = 0; i < n; i++) {
            if (Egg[i].HP <= 0) breakCount++;
        }
        ans = max(ans, breakCount);
        return;
    }
    bool flag = false;//손에든 계란이 깨졌는가?
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;//자기 자신
        if (Egg[i].HP > 0 && Egg[idx].HP > 0) {//둘다 안깨진거면
            flag = true;
            Egg[i].HP -= Egg[idx].Attack;
            Egg[idx].HP -= Egg[i].Attack;
            EggBreak(idx + 1);//바로 오른쪽 계란
            Egg[i].HP += Egg[idx].Attack;
            Egg[idx].HP += Egg[i].Attack;
        }
    }
    if(!flag) EggBreak(idx + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    EggBreak(0);//계란깨기
    cout << ans;//출력
    return 0;
}
