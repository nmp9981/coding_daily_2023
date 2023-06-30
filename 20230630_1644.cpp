#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 4000001;
int primeSize;//소수 개수
bool isNotPrime[maxi];//소수가 아닌가?
vector<int> primeList;//소수 목록

//에라토스테네스의 체
void Aratos() {
    int rootMax = 2001;
    primeList.push_back(2);
    for (int i = 3; i < rootMax; i += 2) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j < maxi; j += i) isNotPrime[j] = true;
        }
    }

    //소수 넣기
    for (int i = 3; i < maxi; i += 2) {
        if (!isNotPrime[i]) primeList.push_back(i);
    }
    primeSize = primeList.size();
}
//입력
void input() {
    cin >> n;
}
//소수 합
void PrimeSum() {
    int cnt = 0;
    int left = 0;
    int right = 0;
    int sum = primeList[left];
    while (left <= right && right < primeSize) {
        if (sum >= n) {
            if (sum == n) cnt++;//합 일치
            sum -= primeList[left];
            left++;
        }
        else if (sum < n) {
            right++;
            sum += primeList[right];
        }
    }
    cout << cnt;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Aratos();//에라토스테네스의체
    input();//입력
    PrimeSum();//소수 합
    return 0;
}
