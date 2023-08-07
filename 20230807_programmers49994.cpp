#include <string>
using namespace std;

const int maxi = 10;

bool check[15][15][15][15]; //x1, y1에서 x2, y2로 가는 길

int solution(string dirs)
{
    int x = 5, y = 5;
    int answer = 0;
    for(auto d : dirs){
        int dx = x;
        int dy = y;
        if(d == 'L'){
            dx -= 1;
        }
        else if(d == 'R'){
            dx += 1;
        }
        else if(d == 'U'){
            dy -= 1;
        }
        else if(d == 'D'){
            dy += 1;
        }
        if(dx < 0 || dx > maxi || dy < 0 || dy >maxi)
            continue;
        if(!check[x][y][dx][dy]){
            check[x][y][dx][dy] = true;
            check[dx][dy][x][y] = true;
            answer += 1;
        }
        x = dx;
        y = dy;
    }
    return answer;
}
