#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Imti {
    int screen, store, cnt;
};
int s;
const int maxi = 2001;
queue<Imti> q;//화면,저장
int visit[maxi];//화면에 i개 이모티콘 방문 시간

//입력
void input() {
    cin >> s;

    q.push({ 1,0 });
    memset(visit, -1, sizeof(visit));//초기화
    visit[1] = 0;
}

//이모티콘
void Imog() {
    while (!q.empty()) {
        int screen = q.front().screen;
        int store = q.front().store;
        int cnt = q.front().cnt;
        q.pop();

        if (screen == s) {//목표 달성
            cout << cnt;
            return;
        }

        //복사
        q.push({ screen,screen,cnt+1 });
        //붙여넣기
        if (visit[screen + store] == -1) {
            if (screen + store < maxi) {
                visit[screen + store] == cnt + 1;
                q.push({ screen + store,store,cnt + 1 });
            }
        }
        //삭제
        if (screen > 0) {
            if (visit[screen - 1] == -1) {
                visit[screen - 1] = cnt + 1;
                q.push({ screen - 1,store,cnt + 1 });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Imog();//이모티콘
    return 0;
}
