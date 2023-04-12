#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree {
private:
    int n, m, year;
    static const int maxi = 11;
    int addFood[maxi][maxi];//추가 양분
    int food[maxi][maxi];//양분
    vector<int> world[maxi][maxi];//맵 정보
    vector<int> death[maxi][maxi];//죽은 나무
    //8방 탐색
    int dx[8] = { -1,-1,-1,1,1,1,0,0 };
    int dy[8] = { -1,0,1,-1,0,1,-1,1 };
public:
    Tree() {};//디폴트 생성자
    void input();//입력
    void Season();//계절
    void Spring();//봄
    void Summer();//여름
    void Fall();//가을
    void Winter();//겨울
    void LiveTree();//살아남은 나무 수
};

//입력
void Tree::input() {
    cin >> n>>m>>year;
    //양분 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> addFood[i][j];
            food[i][j] = 5;//맨처음 양분은 5
        }
    }
    //나무 위치, 나이 등록
    for (int i = 0; i < m; i++) {
        int r, c, age;
        cin >> r >> c >> age;
        world[r-1][c-1].push_back(age);
    }
}
//봄
void Tree::Spring() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //양분 먹기
            vector<int> survive;//생존
            for (int k = 0; k < world[i][j].size(); k++) {
                int year = world[i][j][k];//나이
                //먹을 수 있다.
                if (food[i][j] >= year) {
                    food[i][j] -= year;
                    survive.push_back(year+1);
                }
                else death[i][j].push_back(year);//사망
            }
            //초기화 후 살아남은 나무 넣기
            world[i][j].clear();
            for (int k = 0; k < survive.size(); k++) world[i][j].push_back(survive[k]);
        }
    }
}
//여름
void Tree::Summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //죽은 나무 -> 양분
            for (int k = 0; k < death[i][j].size(); k++) {
                int add = death[i][j][k]/2;//추가량
                food[i][j] += add;
            }
            death[i][j].clear();//초기화
        }
    }
}
//가을
void Tree::Fall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < world[i][j].size(); k++) {
                //나이가 5의 배수
                if (world[i][j][k] % 5 == 0) {
                    for (int dir = 0; dir < 8; dir++) {//인접한 8개의 칸
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
                        world[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}
//겨울
void Tree::Winter() {
    //양분 추가
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            food[i][j] += addFood[i][j];
            sort(world[i][j].begin(),world[i][j].end());//내년을 위해 나이순 정렬
        }
    }
}
//계절
void Tree::Season() {
    while (year--) {
        Spring();//봄
        Summer();//여름
        Fall();//가을
        Winter();//겨울
    }
}
//살아남은 나무의 수
void Tree::LiveTree() {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            total += world[i][j].size();
        }
    }
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Tree tree;
    tree.input();//입력
    tree.Season();//계절
    tree.LiveTree();//살아남은 나무의 수
    return 0;
}
