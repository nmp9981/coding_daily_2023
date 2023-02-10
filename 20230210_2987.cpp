#include <iostream>
using namespace std;

struct Triangle {
    double xpos, ypos;
};
int n;
Triangle tri[3];//삼각형 배열

//땅의 넓이
void Area() {
    int area = abs(tri[0].xpos * (tri[1].ypos - tri[2].ypos) + tri[1].xpos * (tri[2].ypos - tri[0].ypos) + tri[2].xpos * (tri[0].ypos - tri[1].ypos));
    double square = ((double)area) / 2.0;
    printf("%.1f\n", square);
}
//외적
int Cross(int ax, int ay, int bx,int by) {
    return ax * by - ay * bx;
}
//판별
bool isIn(int a, int b) {
    int x1 = a - tri[0].xpos; int y1 = b - tri[0].ypos;//pa
    int x2 = a-tri[1].xpos; int y2 = b-tri[1].ypos;//pb
    int x3 = a-tri[2].xpos; int y3 = b-tri[2].ypos;//pc

    if (Cross(x1,y1,x2,y2) >= 0 && Cross(x2,y2,x3,y3) >= 0 && Cross(x3,y3,x1,y1) >= 0) return true;
    if (Cross(x1, y1, x2, y2) <= 0 && Cross(x2, y2, x3, y3) <= 0 && Cross(x3, y3, x1, y1) <= 0) return true;
    return false;
}
//입력
void input() {
    cin >> tri[0].xpos >> tri[0].ypos;
    cin >> tri[1].xpos >> tri[1].ypos;
    cin >> tri[2].xpos >> tri[2].ypos;
    Area();
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (isIn(a, b)) cnt++;
    }
    cout << cnt;//출력
}
int main() {
    //빠른 입력
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    input();//입력
    return 0;
}
