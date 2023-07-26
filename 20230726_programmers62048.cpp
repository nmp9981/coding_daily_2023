using namespace std;
typedef long long ll;

//최대 공약수
ll Gcd(ll x,ll y){
    ll a,b,r;
    if(x>y){
        a = x;
        b = y;
    }else{
        a = y;
        b = x;
    }
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
long long solution(int w,int h) {
    ll W = (ll) w;
    ll H = (ll) h;
    ll cntSquare = Gcd(W,H);
    ll smallW = W/cntSquare;
    ll smallH = H/cntSquare;
    return W*H-cntSquare*(smallW+smallH-1);
}
