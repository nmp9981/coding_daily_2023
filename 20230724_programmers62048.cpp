using namespace std;
typedef long long ll;

//최대 공약수
ll Gcd(ll w,ll h){
    ll x,y;
    //큰수가 x
    if(w>h){
        x = w;
        y = h;
    }else{
        x = h;
        y = w;
    }
    while(y!=0){
        ll r = x%y;
        x = y;
        y = r;
    }
    return x;
}

long long solution(int w,int h) {
    ll W = w;
    ll H = h;
    ll squareCount = Gcd(W,H);//공통 사각형 개수
    ll restW = w/squareCount;//작은 직사각형 가로 길이
    ll restH = h/squareCount;//작은 직사각형 세로 길이
    return W*H-squareCount*(restW+restH-1);//전체 - 대각선을 지나는 사각형 개수
}
