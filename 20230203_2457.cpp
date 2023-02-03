#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 501;
const int inf = 80000000;
int month[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };//달력 일 수
vector<pair<int, int>> flower;//꽃의 정보

//min
int inline min(int x, int y) {
    return x > y ? y : x;
}
//정렬 기준
bool cmp(pair<int, int > a, pair<int, int> b) {
    if (a.first < b.first) return true;//피는건 오름차순
    return false;
}
//일수로 바꾸기
int Change(int st, int ed) {
    return month[st - 1] + ed;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int startMonth, startDay, endMonth, endDay;
        cin >> startMonth >> startDay >> endMonth >> endDay;
        int flowerStart = Change(startMonth, startDay);
        int flowerend = Change(endMonth, endDay);
        flower.push_back({ flowerStart,flowerend });
    }
    sort(flower.begin(), flower.end(), cmp);//피는건 오름차순
}
//꽃 심기
int garden() {
    int left = 60; int right = 0;//가장 끝쪽
    int cnt = 1;//꽃의 개수
    for (int i = 0; i < flower.size(); i++) {
        //새로운 기간
        int flowerSt = flower[i].first;
        int flowerEd = flower[i].second;

        //시작점 기준
        if (flowerSt <= left) {
            if (right < flowerEd) right = flowerEd;

            if (right > 334) break;//12/1 이후
        }else{
            //붕뜸 => 심기 불가
            if (right < flowerSt) return 0;

            left = right;
            right = flowerEd;
            cnt++;
        }
    }
    if (right <= 334) return 0;//11/30까지 심을 수 없다
    return cnt;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    cout<<garden();//꽃 심기
    return 0;
}
