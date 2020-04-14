#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

ll N,Q;
string s;
vector<char> t,d;
//愚直にシミュレーション
//Xが左に落ちないときtrue
bool checkl(ll X){
    rep(i,Q){
        if(t[i] == s[X]){
            if(d[i] == 'R'){
                X++;
            }
            else{
                X--;
            }
        }
        if(X == -1){
            return false;
        }
    }
    return true;
}
//Xが右に落ちないときtrue
bool checkr(ll X){
    rep(i,Q){
        if(t[i] == s[X]){
            if(d[i] == 'R'){
                X++;
            }
            else{
                X--;
            }
            if(X == N){
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin>>N>>Q>>s;
    t.resize(Q);d.resize(Q);
    rep(i,Q){
        cin>>t[i]>>d[i];
    }
    //左に落ちるとき
    ll ng = -1;ll ok = N;
    while(ok - ng > 1){
        ll mid = (ok+ng)/2;
        if(checkl(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    ll l = ok;
    //右に落ちるとき
    ok = -1; ng = N;
    while(ng - ok > 1){
        ll mid = (ok+ng)/2;
        if(checkr(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    ll r = ok;
    //cerr<<l<<" "<<r<<endl;
    cout<<r-l+1<<endl;
}