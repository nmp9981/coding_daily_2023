#include <iostream>
using namespace std;

int n, k, q;
const int maxi = 10001;
int notRead[maxi];//읽지 않은 사람의 수
char sender[maxi];//송신자
bool isRead[26];//안읽은 사람

//입력
void input() {
    cin >> n>>k>>q;
    for (int i = 1; i <= k; i++) cin >> notRead[i] >> sender[i];
}
//카톡
void Talk() {
    int people = notRead[q];

    if (people == 0) cout << -1;//다 읽음
    else {
        for (int i = 1; i <= k; i++) {
            if (people <= notRead[i]) isRead[sender[i] - 'A'] = true;
        }
        for (int i = 1; i < n; i++) {
            if (!isRead[i]) cout << char(i + 'A') << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Talk();//카톡
    return 0;
}
