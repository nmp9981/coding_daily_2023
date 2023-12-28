#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000001

using namespace std;

bool cmp(int &a, int &b) {
    return a > b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> kind(MAX); // 각 귤의 종류의 개수를 담은 벡터
    
    // 각 귤의 종류의 개수 세기
    for (int t: tangerine) {
        kind[t]++;
    }
    
    // 종류가 많은 귤부터 담기 위해 내림차순 정렬
    sort(kind.begin(), kind.end(), cmp);
    
    for (int i=0; i<kind.size(); i++) {
        if (kind[i] < k) {
            answer++; // 담은 귤의 종류 개수
            k -= kind[i]; // 담은 귤 개수
        } else if (kind[i] >= k) {
            answer++;
            break;
        }
    }
    
    return answer;
}
