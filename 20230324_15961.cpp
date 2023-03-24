#include <iostream>
using namespace std;

int n,d,k,c;
const int maxi = 6000001;
const int maxCount = 3001;
int sushi[maxi];//초밥
int kind = 1;//k개를 담은 접시에 있는 종류
int Eat[maxCount];//i번 초밥을 먹은 개수
int eatSize;//최대 먹을 수 있는 초밥 종류의 개수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>d>>k>>c;
    for (int i = 0; i < n; i++) cin >> sushi[i];
    //슬라이딩 윈도우를 위해 한줄 추가
    for (int i = n; i < 2 * n; i++) sushi[i] = sushi[i - n];
}
//초밥 먹기
void EatSushi() {
    Eat[c] = 1;//쿠폰
    //초기 k개
    for (int i = 0; i < k; i++) {
        Eat[sushi[i]]++;
        if (Eat[sushi[i]] == 1) kind++;
    }
    //k개씩 먹기
    for (int i = k; i < 2 * n; i++) {
        //이전 초밥 뱉기
        Eat[sushi[i-k]]--;
        if (Eat[sushi[i - k]] == 0) kind--;

        //현재 초밥 먹기
        Eat[sushi[i]]++;
        if (Eat[sushi[i]] == 1) kind++;
        eatSize = max(eatSize, kind);
    }
    cout << eatSize;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    EatSushi();//초밥 먹기
    return 0;
}
