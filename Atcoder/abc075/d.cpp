#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;
const int INF = 1e9;

vector<ll> h;
ll N,A,B;

bool check(ll X){
    auto h2 = h;
    //まとめて爆風を処理
    rep(i,N){
        h2[i] = max(0LL, h[i]-X*B);
    }
    //個々にA-Bずつ減らしていく
    ll cnt = 0;
    rep(i,N){
        cnt += h2[i]/(A-B);
        if(h2[i]%(A-B)!=0){
            cnt++;
        }
    }
    return cnt<=X;
}

int main() {
    cin>>N>>A>>B;
    h.resize(N);
    rep(i,N)cin>>h[i];
    ll ng = 0, ok = INF;
    while(ok - ng > 1){
        ll mid = (ok+ng)/2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}