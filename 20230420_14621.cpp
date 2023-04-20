#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
const int maxi = 1001;
char school[maxi];//학교
vector<pair<int,pair<int,int>>> Road;//도로
int root[maxi];//각 노드의 루트노드

//입력
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> school[i];
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        Road.push_back({ d,{a,b} });
        Road.push_back({ d,{b,a} });//양방향
    }
}
//루트 노드
int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}
//연결
void Connect(int x, int y) {
    if (x > y) root[x] = y;
    else root[y] = x;
}
//초기화
void init() {
    for (int i = 1; i <= n; i++) root[i] = i;//루트 노드
    sort(Road.begin(), Road.end());//거리순 정렬
}
//사심 경로
void SelfLess() {
    int total = 0;
    int node = 0;
    for (int i = 0; i < Road.size(); i++) {
        int dist = Road[i].first;
        int a = Road[i].second.first;
        int b = Road[i].second.second;

        if (school[a] == school[b]) continue;//같으면 연결 X

        //연결
        int findA = Find(a);
        int findB = Find(b);
        if (findA != findB) {
            Connect(findA, findB);
            total += dist;
            node++;
        }
        //모두 연결
        if (node == n - 1) {
            cout << total;
            return;
        }
    }
    cout << -1;//연결 불가
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    init();//초기화
    SelfLess();//사심 경로
    return 0;
}
