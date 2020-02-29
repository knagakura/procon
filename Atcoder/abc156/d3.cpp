#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x
#define bit(k) (1LL<<(k))

typedef long long ll;
const ll MAX = 5100000;
const ll MOD = 1000000007;
ll n,a,b;
vector<ll> ue(MAX,1),shita(MAX+1,1);
ll modpow(ll a, ll n, int mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


long long modinv(long long a) {
    ll res = modpow(a, MOD - 2, MOD);
    //cerr<<"modinv"<<a<<": "<<res<<endl;
    return res;
}
void cominit(){
    ue[0] = 1;
    shita[0] = 1;
    rep(i,MAX){
        ue[i+1] = ((ue[i]%MOD) * ((n - i) % MOD)%MOD) * (modinv(i+1)%MOD);
        ue[i+1] %=MOD;
    }
}

ll COM(ll w){
    return ue[w];
}
int main() {
    cin>>n>>a>>b;
    cominit();
    /*
    rep(i,n+1){
        cerr<<ue[i]<<" ";
    }
    cerr<<endl;
    */
    ll ans = modpow(2,n,MOD) - 1;
    ans = ((ans+MOD%MOD) - ue[a] + MOD) % MOD;
    ans = ((ans+MOD%MOD) - ue[b] + MOD) % MOD;
    cout<<(ans+MOD)%MOD<<endl;
}