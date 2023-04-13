#include <iostream>
#include <vector>
using namespace std;

int n, d, k, c;
const int maxi = 3001;
int maxCnt = 0;//최대 개수
int sushi[maxi];//i번 초밥의 개수
vector<int> dish;//접시

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        dish.push_back(x);
    }
    //뒤쪽
    for (int i = 0; i < n; i++) {
        int add = dish[i];
        dish.push_back(add);
    }
}
//먹기
void Eat() {
    //쿠폰
    sushi[c] = 1;
    int cnt = 1;
    //처음 k개
    for (int i = 0; i < k; i++) {
        sushi[dish[i]]++;
        if (sushi[dish[i]] == 1) cnt++;
    }
    maxCnt = cnt;
    //초밥 먹기
    for (int i = k; i < dish.size(); i++) {
        //초밥 뱉기
        sushi[dish[i - k]]--;
        if (sushi[dish[i - k]] == 0) cnt--;
        //초밥 먹기
        sushi[dish[i]]++;
        if (sushi[dish[i]] == 1) cnt++;

        //갱신
        maxCnt = max(maxCnt, cnt);//가짓수 갱신
    }
    cout << maxCnt;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Eat();//먹기
    return 0;
}
