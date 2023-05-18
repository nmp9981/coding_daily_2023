#include <iostream>
using namespace std;

int n,k,q;
const int maxi = 10001;
bool isRead[26];//읽었는가?
int notRead[maxi];//안읽은 사람
char sender[maxi];//발신자

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void Input() {
    cin >> n>>k>>q;
    for (int i = 1; i <= k; i++) cin >> notRead[i] >> sender[i];
}
//읽지 않은 사람
void NotRead() {
    if (notRead[q] == 0) cout << -1;
    else {
        int people = notRead[q];
        for (int i = 1; i <= k; i++) {
            if (people <= notRead[i]) {
                isRead[sender[i] - 'A'] = true;
            }
        }
        //인원 수
        for (int i = 1; i < n; i++) {
            if (!isRead[i]) cout << char(i + 'A') << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    NotRead();//읽지 않은 사람
    return 0;
}
